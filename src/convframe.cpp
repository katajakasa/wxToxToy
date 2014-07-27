#include "convframe.h"
#include "wxtoxframe.h"
#include "icon-32.xpm"

ConversationFrame::ConversationFrame(wxWindow* parent, wxToxTick *tox, ToxFriend f)
    : ConvFrameProto(parent), m_tox(tox), m_friend(f)
{
    SetTitle(m_friend.getNick());
    SetIcon(icon_32_xpm);
}

ConversationFrame::~ConversationFrame() {
    ((wxToxFrame*)m_parent)->closeFrame(m_friend.getId());
}


int32_t ConversationFrame::getFriendId() {
    return m_friend.getId();
}

void ConversationFrame::addMessage(wxString username, wxString message) {
    convHtmlWindow->AppendToPage(_("<p><span style=\"font-weight: bold;\">"));
    convHtmlWindow->AppendToPage(username);
    convHtmlWindow->AppendToPage(_("</span><span class=\"message\">"));
    convHtmlWindow->AppendToPage(message);
    convHtmlWindow->AppendToPage(_("</span></p>"));
}

void ConversationFrame::addFriendMessage(wxString message) {
    addMessage(m_friend.getNick(), message);
}

void ConversationFrame::addOwnMessage(wxString message) {
    addMessage(m_tox->getNick(), message);
}

void ConversationFrame::onSendMessage(wxCommandEvent& event) {
    wxString msg = convMessageField->GetValue();
    convMessageField->SetValue(_(""));
    m_friend.sendMessage(msg);
    addOwnMessage(msg);
}
