#include "toxfriend.h"

ToxFriend::ToxFriend(Tox *tox, int32_t id) : m_tox(tox), m_id(id) {}
ToxFriend::~ToxFriend() {}

wxString ToxFriend::getNick() {
    uint8_t nick[TOX_MAX_NAME_LENGTH];
    int len = tox_get_name(m_tox, m_id, nick);
    printf("%d\n", len);
    return wxString::FromUTF8((const char*)nick, len);
}

FriendStatus ToxFriend::getStatus() {
    return STATUS_ONLINE;
}

wxString ToxFriend::getStatusText() {
    uint8_t msg[1024];
    int len = tox_get_status_message(m_tox, m_id, msg, 1024);
    return wxString::FromUTF8((const char*)msg, len);
}

bool ToxFriend::isTyping() {
    return tox_get_is_typing(m_tox, m_id);
}

bool ToxFriend::exists() {
    return tox_friend_exists(m_tox, m_id);
}

unsigned int ToxFriend::sendMessage(wxString message) {
    wxCharBuffer buffer = message.ToUTF8();
    return tox_send_message(m_tox, m_id, message.data(), message.length());
}