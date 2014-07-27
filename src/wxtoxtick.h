#ifndef _WXTOXTICK_H
#define _WXTOXTICK_H

#include <wx/timer.h>
#include <tox/tox.h>
#include <wx/vector.h>

#include "toxfriend.h"

class wxToxTick : public wxTimer {
protected:
    Tox *m_tox;
    wxWindow *m_parent;
    
public:
    wxToxTick(wxWindow *parent);
    ~wxToxTick();
    void Notify();
    
    void begin();

    wxString getNick();
    wxString getKey();
    wxString getStatusText();

    void setNick(wxString nick);
    void setStatusText(wxString text);

    ToxFriend getFriend(int32_t friend_id);
    wxVector<ToxFriend> getFriendList();
    void addFriend(wxString friend_key, wxString message);

    void saveState();
    
    // Unique
    void onFriendRequest(const uint8_t *pki, const uint8_t *data, uint16_t length);

    // Complex
    void onFriendMessage(int32_t friend_id, const uint8_t *data, uint16_t length);
    void onFriendAction(int32_t friend_id, const uint8_t *data, uint16_t length);
    void onNameChange(int32_t friend_id, const uint8_t *data, uint16_t length);
    void onStatusMessageChange(int32_t friend_id, const uint8_t *data, uint16_t length);

    // Simple

    void onConnectionChange(int32_t friend_id, uint8_t data);
    void onTypingChange(int32_t friend_id, uint8_t data);
    void onUserStatusChange(int32_t friend_id, uint8_t data);
};

#endif // _WXTOXTICK_H