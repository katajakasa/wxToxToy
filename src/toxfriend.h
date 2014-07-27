#ifndef _TOXFRIEND_H
#define _TOXFRIEND_H

#include <wx/string.h>
#include <tox/tox.h>

enum FriendStatus {
    STATUS_ONLINE,
    STATUS_AWAY,
    STATUS_BUSY,
    STATUS_OFFLINE,
};

class ToxFriend {
protected:
    Tox *m_tox;
    int32_t m_id;

public:
    ToxFriend(Tox *tox, int32_t id);
    ~ToxFriend();

    wxString getNick();
    FriendStatus getStatus();
    wxString getStatusText();
    bool isTyping();
    bool exists();
    unsigned int sendMessage(wxString message);
    int32_t getId() { return m_id; }
};

#endif // _TOXFRIEND_H