#ifndef _CONVERSATIONFRAME_H
#define _CONVERSATIONFRAME_H

#include "wxtoxgui.h"
#include "wxtoxtick.h"
#include "toxfriend.h"

class ConversationFrame : public ConvFrameProto {
protected:
    wxToxTick *m_tox;
    ToxFriend m_friend;

public:
    ConversationFrame(wxWindow* parent, wxToxTick *tox, ToxFriend f);
    ~ConversationFrame();

    int32_t getFriendId();
    void addMessage(wxString username, wxString message);
    void addFriendMessage(wxString message);
    void addOwnMessage(wxString message);

    void onSendMessage(wxCommandEvent& event);
};

#endif // _CONVERSATIONFRAME_H
