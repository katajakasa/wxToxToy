#include <wx/file.h>

#include "wxtoxtick.h"
#include "utils.h"
#include "log.h"
#include "wxtoxframe.h"

// Bootstrap data

#define BOOTSTRAP_ADDRESS "23.226.230.47"
#define BOOTSTRAP_PORT 33445
#define BOOTSTRAP_KEY "A09162D68618E742FFBCA1C2C70385E6679604B2D80EA6E84AD0996A1AC8A074"
#define MY_NAME "wxToxUser"

// Other defines

#define FRIENDLIST_MAX_SIZE 1024

// Macros

#define declare_simple_tox_cb(FN_NAME) \
    void _ ## FN_NAME(Tox *tox, int32_t friend_id, uint8_t data, void *userdata) {\
        ((wxToxTick*)userdata)->FN_NAME(friend_id, data); \
    }

#define declare_complex_tox_cb(FN_NAME) \
    void _ ## FN_NAME(Tox *tox, int32_t friend_id, const uint8_t *data, uint16_t length, void *userdata) {\
        ((wxToxTick*)userdata)->FN_NAME(friend_id, data, length); \
    }

#define declare_tox_caller(CB_FUNC, FN_NAME) \
    CB_FUNC(m_tox, _ ## FN_NAME, (void*)this)

// Unique

void _onFriendRequest(Tox *tox, const uint8_t *pki, const uint8_t *data, uint16_t length, void *userdata) {
    ((wxToxTick*)userdata)->onFriendRequest(pki, data, length); 
}

// Complex

declare_complex_tox_cb(onFriendMessage);
declare_complex_tox_cb(onFriendAction);
declare_complex_tox_cb(onNameChange);
declare_complex_tox_cb(onStatusMessageChange);

// Simple

declare_simple_tox_cb(onUserStatusChange);
declare_simple_tox_cb(onTypingChange);
declare_simple_tox_cb(onConnectionChange);

// Functions

wxToxTick::wxToxTick(wxWindow *parent) : wxTimer(), m_parent(parent) {
    // Enable Tox client
    m_tox = tox_new(TOX_ENABLE_IPV6_DEFAULT);
    
    wxFile file;
    if(file.Open("tox.dat")) {
        size_t len = file.Length();
        uint8_t buffer[len];
        file.Read((void*)buffer, len);
        tox_load(m_tox, buffer, len);
        file.Close();
    } else {
        char *pub_key = hex_string_to_bin(BOOTSTRAP_KEY);
        tox_set_name(m_tox, (const uint8_t*)MY_NAME, strlen(MY_NAME));
        tox_bootstrap_from_address(
            m_tox,
            BOOTSTRAP_ADDRESS,
            TOX_ENABLE_IPV6_DEFAULT,
            BOOTSTRAP_PORT,
            (uint8_t*)pub_key);
        saveState();
    }
    
    // Callbacks
    declare_tox_caller(tox_callback_connection_status, onConnectionChange);
    declare_tox_caller(tox_callback_typing_change, onTypingChange);
    declare_tox_caller(tox_callback_friend_request, onFriendRequest);
    declare_tox_caller(tox_callback_friend_message, onFriendMessage);
    declare_tox_caller(tox_callback_name_change, onNameChange);
    declare_tox_caller(tox_callback_user_status, onUserStatusChange);
    declare_tox_caller(tox_callback_status_message, onStatusMessageChange);
    declare_tox_caller(tox_callback_friend_action, onFriendAction);
}

wxString wxToxTick::getNick() {
    uint8_t nick[TOX_MAX_NAME_LENGTH];
    int len = tox_get_self_name(m_tox, nick);
    return wxString::FromUTF8((const char*)nick, len);
}

wxString wxToxTick::getKey() {
    uint8_t key[TOX_FRIEND_ADDRESS_SIZE];
    tox_get_address(m_tox, key);
    wxString out;
    for(unsigned int i = 0; i < TOX_FRIEND_ADDRESS_SIZE; i++) {
        out << wxString::Format("%02X", key[i]);
    }
    return out;
}

wxString wxToxTick::getStatusText() {
    uint8_t msg[1024];
    int len = tox_get_self_status_message(m_tox, msg, 1024);
    return wxString::FromUTF8((const char*)msg, len);
}

void wxToxTick::setNick(wxString nick) {
    wxCharBuffer buffer = nick.ToUTF8();
    tox_set_name(m_tox, (uint8_t*)buffer.data(), buffer.length());
    saveState();
}

void wxToxTick::setStatusText(wxString text) {
    wxCharBuffer buffer = text.ToUTF8();
    tox_set_status_message(m_tox, (uint8_t*)buffer.data(), buffer.length());
    saveState();
}

wxVector<ToxFriend> wxToxTick::getFriendList() {
    int32_t friends[FRIENDLIST_MAX_SIZE];
    unsigned int len = tox_get_friendlist(m_tox, friends, FRIENDLIST_MAX_SIZE);

    wxVector<ToxFriend> list;
    for(unsigned int i = 0; i < len; i++) {
        ToxFriend f(m_tox, friends[i]);
        list.push_back(f);
    }
    return list;
}

void wxToxTick::addFriend(wxString friend_key, wxString message) {
    char* m = hex_string_to_bin(friend_key.MakeLower().ToAscii());
    wxCharBuffer buffer = message.ToUTF8();
    tox_add_friend(m_tox, (uint8_t*)m, (uint8_t*)buffer.data(), buffer.length());
    free(m);
    saveState();
}

ToxFriend wxToxTick::getFriend(int32_t friend_id) {
    return ToxFriend(m_tox, friend_id);
}

void wxToxTick::begin() {
    Start(tox_do_interval(m_tox));
    log_add(_(__PRETTY_FUNCTION__));
}

// Unique

void wxToxTick::onFriendRequest(const uint8_t *pki, const uint8_t *data, uint16_t length) {
    log_add(_(__PRETTY_FUNCTION__));
}

// Complex

void wxToxTick::onFriendMessage(int32_t friend_id, const uint8_t *data, uint16_t length) {
    log_add(_(__PRETTY_FUNCTION__));
    log_add(wxString::FromUTF8((const char*)data, length));
    ((wxToxFrame*)m_parent)->addMessageToFrame(friend_id, wxString::FromUTF8((const char*)data, length));
}

void wxToxTick::onFriendAction(int32_t friend_id, const uint8_t *data, uint16_t length) {
    log_add(_(__PRETTY_FUNCTION__));
    ((wxToxFrame*)m_parent)->updateFriendList();
    saveState();
}

void wxToxTick::onNameChange(int32_t friend_id, const uint8_t *data, uint16_t length) {
    log_add(_(__PRETTY_FUNCTION__));
    ((wxToxFrame*)m_parent)->updateFriendList();
    saveState();
}

void wxToxTick::onStatusMessageChange(int32_t friend_id, const uint8_t *data, uint16_t length) {
    log_add(_(__PRETTY_FUNCTION__));
    ((wxToxFrame*)m_parent)->updateFriendList();
    saveState();
}

// Simple

void wxToxTick::onConnectionChange(int32_t friend_id, uint8_t receipt_id) {
    log_add(_(__PRETTY_FUNCTION__));
}

void wxToxTick::onTypingChange(int32_t friend_id, uint8_t receipt_id) {
    log_add(_(__PRETTY_FUNCTION__));
}

void wxToxTick::onUserStatusChange(int32_t friend_id, uint8_t receipt_id) {
    log_add(_(__PRETTY_FUNCTION__));
}

// Other

void wxToxTick::Notify() {
    tox_do(m_tox);
}

void wxToxTick::saveState() {
    wxFile file;
    if(file.Open("tox.dat", wxFile::write)) {
        size_t len = tox_size(m_tox);
        uint8_t buffer[len];
        tox_save(m_tox, buffer);
        file.Write((void*)buffer, len);
        file.Flush();
        file.Close();
    }
}

wxToxTick::~wxToxTick() {
    tox_kill(m_tox);
}