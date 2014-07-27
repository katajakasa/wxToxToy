///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 26 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WXTOXGUI_H__
#define __WXTOXGUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/srchctrl.h>
#include <wx/sizer.h>
#include <wx/scrolwin.h>
#include <wx/panel.h>
#include <wx/html/htmlwin.h>
#include <wx/aui/auibook.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
#include <wx/splitter.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/statbox.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class wxToxFrameProto
///////////////////////////////////////////////////////////////////////////////
class wxToxFrameProto : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* mainMenuBar;
		wxMenu* fileMenu;
		wxMenu* contactMenuItem;
		wxMenu* onlineStatusMenu;
		wxMenu* helpMenu;
		wxAuiNotebook* baseNotebook;
		wxPanel* friendListPanel;
		wxSearchCtrl* friendListSearch;
		wxScrolledWindow* friendListScrollPanel;
		wxFlexGridSizer* friendsListSizer;
		wxPanel* chatListPanel;
		wxPanel* eventListPanel;
		wxPanel* logHtmlWindow;
		wxHtmlWindow* logHtmlPanel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onSettingsItemClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void onExitItemClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAddFriendItemClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOnlineStatusSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAwayStatusSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void onBusyStatusSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOfflineStatusSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAboutItemClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		wxToxFrameProto( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("wxTox"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 300,500 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~wxToxFrameProto();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ConvFrameProto
///////////////////////////////////////////////////////////////////////////////
class ConvFrameProto : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* convMenuBar;
		wxMenu* convFileMenu;
		wxStatusBar* convStatusBar;
		wxSplitterWindow* convBaseSplitter;
		wxPanel* convTopPanel;
		wxHtmlWindow* convHtmlWindow;
		wxPanel* convBottomPanel;
		wxTextCtrl* convMessageField;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void onConversationLinkClicked( wxHtmlLinkEvent& event ) { event.Skip(); }
		virtual void onSendMessage( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ConvFrameProto( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Conversation"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 625,449 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~ConvFrameProto();
		
		void convBaseSplitterOnIdle( wxIdleEvent& )
		{
			convBaseSplitter->SetSashPosition( 300 );
			convBaseSplitter->Disconnect( wxEVT_IDLE, wxIdleEventHandler( ConvFrameProto::convBaseSplitterOnIdle ), NULL, this );
		}
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SettingsDialogProto
///////////////////////////////////////////////////////////////////////////////
class SettingsDialogProto : public wxDialog 
{
	private:
	
	protected:
		wxPanel* settingsBasePanel;
		wxStaticBitmap* avatarBitmap;
		wxStaticText* nickLabel;
		wxTextCtrl* nickField;
		wxStaticText* userKeyLabel;
		wxTextCtrl* userKeyField;
		wxStaticText* statusTextLabel;
		wxTextCtrl* statusTextField;
		wxStaticText* fileDirectoryLabel;
		wxTextCtrl* fileDirectoryField;
		wxCheckBox* fileAutosaveField;
		wxStdDialogButtonSizer* settingsDialogButtons;
		wxButton* settingsDialogButtonsOK;
		wxButton* settingsDialogButtonsCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onNickChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void onStatusTextChange( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SettingsDialogProto( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 528,296 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~SettingsDialogProto();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AddFriendDialogProto
///////////////////////////////////////////////////////////////////////////////
class AddFriendDialogProto : public wxDialog 
{
	private:
	
	protected:
		wxPanel* addFriendBasePanel;
		wxStaticText* userKeyLabel;
		wxTextCtrl* userKeyField;
		wxStaticText* userMessageLabel;
		wxTextCtrl* userMessageField;
		wxStdDialogButtonSizer* addFriendDialogButtons;
		wxButton* addFriendDialogButtonsOK;
		wxButton* addFriendDialogButtonsCancel;
	
	public:
		
		AddFriendDialogProto( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Add friend"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 433,183 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~AddFriendDialogProto();
	
};

#endif //__WXTOXGUI_H__
