#ifndef _WXTOXFRAME_H
#define _WXTOXFRAME_H

#include "wxtoxgui.h"
#include "wxtoxtick.h"
#include "convframe.h"

class wxToxFrame : public wxToxFrameProto {
protected:
    wxToxTick *tox_tick;
    wxVector <ConversationFrame*> m_convFrames;
    
public:
    wxToxFrame(wxFrame *frame);
    ~wxToxFrame();

    void updateFriendList();

    ConversationFrame* findConvFrame(int32_t friend_id);
    void addMessageToFrame(int32_t friend_id, wxString message);
    void closeFrame(int32_t friend_id);
    ConversationFrame* openFrame(int32_t friend_id);
    
    void onExitItemClick(wxCommandEvent& event);
    void onSettingsItemClick(wxCommandEvent& event);
	void onAddFriendItemClick(wxCommandEvent& event);
	void onAboutItemClick(wxCommandEvent& event);
};

#endif // _WXTOXFRAME_H
