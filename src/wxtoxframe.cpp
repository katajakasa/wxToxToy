#include <wx/aboutdlg.h>

#include "wxtoxframe.h"
#include "settingsdialog.h"
#include "addfrienddialog.h"
#include "icon-32.xpm"
#include "license.h"
#include "log.h"

wxToxFrame::wxToxFrame(wxFrame *frame) : wxToxFrameProto(frame) {
    tox_tick = new wxToxTick(this);

    log_init(logHtmlPanel);
    log_add(_("Init."));
    wxImage::AddHandler(new wxPNGHandler);
    SetIcon(icon_32_xpm);
    tox_tick->begin();
    updateFriendList();
}

wxToxFrame::~wxToxFrame() {

}

ConversationFrame* wxToxFrame::findConvFrame(int32_t friend_id) {
    for(auto &frame : m_convFrames) {
        if(frame->getFriendId() == friend_id) {
            return frame;
        }
    }
    return 0;
}

void wxToxFrame::addMessageToFrame(int32_t friend_id, wxString message) {
    ConversationFrame *existing_frame = findConvFrame(friend_id);
    if(existing_frame != 0) {
        existing_frame->addFriendMessage(message);
    } else {
        existing_frame = openFrame(friend_id);
        existing_frame->addFriendMessage(message);
    }
}

void wxToxFrame::closeFrame(int32_t friend_id) {
    for(auto it = m_convFrames.begin(); it != m_convFrames.end(); it++) { 
        if((*it)->getFriendId() == friend_id) {
            m_convFrames.erase(it);
            return;
        }
    }
}

ConversationFrame* wxToxFrame::openFrame(int32_t friend_id) {
    ConversationFrame *frame = new ConversationFrame(this, tox_tick, tox_tick->getFriend(friend_id));
    frame->Show(true);
    m_convFrames.push_back(frame);
    return frame;
}

void wxToxFrame::onExitItemClick(wxCommandEvent& event) {
    delete tox_tick;
    Close();
}

void wxToxFrame::updateFriendList() {
    friendsListSizer->Clear(true);

    wxVector<ToxFriend> friends = tox_tick->getFriendList();
    if(friends.size() == 0) {
        wxStaticText *nameLabel = new wxStaticText(
            friendListScrollPanel,
            wxID_ANY,
            wxT("You have no friends :("),
            wxDefaultPosition,
            wxDefaultSize,
            0);
        friendsListSizer->Add(nameLabel, 0, wxALL, 5);
        return;
    } else {
        for(ToxFriend &f : friends) {
            wxStaticText *nameLabel = new wxStaticText(
                friendListScrollPanel,
                wxID_ANY,
                f.getNick().length() == 0 ? _("Unknown") : f.getNick(),
                wxDefaultPosition,
                wxDefaultSize,
                0);
            friendsListSizer->Add(nameLabel, 0, wxALL, 5);
        }
    }

    friendsListSizer->Layout();
}

void wxToxFrame::onAddFriendItemClick(wxCommandEvent& event) {
    AddFriendDialog dialog(this, tox_tick);
    if(dialog.ShowModal() == wxID_OK) {
        dialog.save();
        updateFriendList();
    }
}

void wxToxFrame::onSettingsItemClick(wxCommandEvent& event) {
    SettingsDialog dialog(this, tox_tick);
    if(dialog.ShowModal() == wxID_OK) {
        dialog.save();
    }
}

void wxToxFrame::onAboutItemClick(wxCommandEvent& event) {
    wxAboutDialogInfo info;
    info.SetName(_("wxTox"));
    info.SetVersion(_("0.1"));
    info.SetDescription(_("wxWidgets Tox client"));
    info.SetCopyright(_T("(C) 2014 Tuomas Virtanen <katajakasa@gmail.com>"));
    info.SetLicense(_(mit_license));
    wxAboutBox(info);
}
