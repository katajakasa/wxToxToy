///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 26 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxtoxgui.h"

///////////////////////////////////////////////////////////////////////////

wxToxFrameProto::wxToxFrameProto( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	mainMenuBar = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	wxMenuItem* settingsMenuItem;
	settingsMenuItem = new wxMenuItem( fileMenu, wxID_ANY, wxString( wxT("Settings") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( settingsMenuItem );
	
	fileMenu->AppendSeparator();
	
	wxMenuItem* exitMenuItem;
	exitMenuItem = new wxMenuItem( fileMenu, wxID_ANY, wxString( wxT("Exit") ) + wxT('\t') + wxT("ALT+F4"), wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( exitMenuItem );
	
	mainMenuBar->Append( fileMenu, wxT("File") ); 
	
	contactMenuItem = new wxMenu();
	wxMenuItem* addFriendMenuItem;
	addFriendMenuItem = new wxMenuItem( contactMenuItem, wxID_ANY, wxString( wxT("Add Friend") ) + wxT('\t') + wxT("ALT+A"), wxEmptyString, wxITEM_NORMAL );
	contactMenuItem->Append( addFriendMenuItem );
	
	mainMenuBar->Append( contactMenuItem, wxT("Friends") ); 
	
	onlineStatusMenu = new wxMenu();
	wxMenuItem* onlineStatusMenuItem;
	onlineStatusMenuItem = new wxMenuItem( onlineStatusMenu, wxID_ANY, wxString( wxT("Online") ) + wxT('\t') + wxT("ALT+1"), wxEmptyString, wxITEM_NORMAL );
	onlineStatusMenu->Append( onlineStatusMenuItem );
	
	wxMenuItem* awayStatusMenuItem;
	awayStatusMenuItem = new wxMenuItem( onlineStatusMenu, wxID_ANY, wxString( wxT("Away") ) + wxT('\t') + wxT("ALT+2"), wxEmptyString, wxITEM_NORMAL );
	onlineStatusMenu->Append( awayStatusMenuItem );
	
	wxMenuItem* busyStatusMenuItem;
	busyStatusMenuItem = new wxMenuItem( onlineStatusMenu, wxID_ANY, wxString( wxT("Busy") ) + wxT('\t') + wxT("ALT+3"), wxEmptyString, wxITEM_NORMAL );
	onlineStatusMenu->Append( busyStatusMenuItem );
	
	wxMenuItem* offlineStatusMenuItem;
	offlineStatusMenuItem = new wxMenuItem( onlineStatusMenu, wxID_ANY, wxString( wxT("Offline") ) + wxT('\t') + wxT("ALT+4"), wxEmptyString, wxITEM_NORMAL );
	onlineStatusMenu->Append( offlineStatusMenuItem );
	
	mainMenuBar->Append( onlineStatusMenu, wxT("Status") ); 
	
	helpMenu = new wxMenu();
	wxMenuItem* aboutMenuItem;
	aboutMenuItem = new wxMenuItem( helpMenu, wxID_ANY, wxString( wxT("About ...") ) + wxT('\t') + wxT("F1"), wxEmptyString, wxITEM_NORMAL );
	helpMenu->Append( aboutMenuItem );
	
	mainMenuBar->Append( helpMenu, wxT("Help") ); 
	
	this->SetMenuBar( mainMenuBar );
	
	wxBoxSizer* mainBaseSizer;
	mainBaseSizer = new wxBoxSizer( wxVERTICAL );
	
	baseNotebook = new wxAuiNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_TOP );
	friendListPanel = new wxPanel( baseNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* friendListBaseSizer;
	friendListBaseSizer = new wxFlexGridSizer( 2, 1, 0, 0 );
	friendListBaseSizer->AddGrowableCol( 0 );
	friendListBaseSizer->AddGrowableRow( 1 );
	friendListBaseSizer->SetFlexibleDirection( wxBOTH );
	friendListBaseSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	friendListSearch = new wxSearchCtrl( friendListPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	friendListSearch->ShowSearchButton( false );
	#endif
	friendListSearch->ShowCancelButton( false );
	friendListBaseSizer->Add( friendListSearch, 0, wxALL|wxEXPAND, 5 );
	
	friendListScrollPanel = new wxScrolledWindow( friendListPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	friendListScrollPanel->SetScrollRate( 5, 5 );
	friendsListSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	friendsListSizer->AddGrowableCol( 0 );
	friendsListSizer->SetFlexibleDirection( wxBOTH );
	friendsListSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	friendListScrollPanel->SetSizer( friendsListSizer );
	friendListScrollPanel->Layout();
	friendsListSizer->Fit( friendListScrollPanel );
	friendListBaseSizer->Add( friendListScrollPanel, 1, wxEXPAND | wxALL, 5 );
	
	
	friendListPanel->SetSizer( friendListBaseSizer );
	friendListPanel->Layout();
	friendListBaseSizer->Fit( friendListPanel );
	baseNotebook->AddPage( friendListPanel, wxT("Friends"), false, wxNullBitmap );
	chatListPanel = new wxPanel( baseNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	baseNotebook->AddPage( chatListPanel, wxT("Chats"), false, wxNullBitmap );
	eventListPanel = new wxPanel( baseNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	baseNotebook->AddPage( eventListPanel, wxT("Events"), false, wxNullBitmap );
	logHtmlWindow = new wxPanel( baseNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* logSizer;
	logSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	logSizer->AddGrowableCol( 0 );
	logSizer->AddGrowableRow( 0 );
	logSizer->SetFlexibleDirection( wxBOTH );
	logSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	logHtmlPanel = new wxHtmlWindow( logHtmlWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO );
	logSizer->Add( logHtmlPanel, 0, wxALL|wxEXPAND, 0 );
	
	
	logHtmlWindow->SetSizer( logSizer );
	logHtmlWindow->Layout();
	logSizer->Fit( logHtmlWindow );
	baseNotebook->AddPage( logHtmlWindow, wxT("Log"), false, wxNullBitmap );
	
	mainBaseSizer->Add( baseNotebook, 1, wxEXPAND | wxALL, 0 );
	
	
	this->SetSizer( mainBaseSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( settingsMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxToxFrameProto::onSettingsItemClick ) );
	this->Connect( exitMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxToxFrameProto::onExitItemClick ) );
	this->Connect( addFriendMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxToxFrameProto::onAddFriendItemClick ) );
	this->Connect( onlineStatusMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxToxFrameProto::onOnlineStatusSelect ) );
	this->Connect( awayStatusMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxToxFrameProto::onAwayStatusSelect ) );
	this->Connect( busyStatusMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxToxFrameProto::onBusyStatusSelect ) );
	this->Connect( offlineStatusMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxToxFrameProto::onOfflineStatusSelect ) );
	this->Connect( aboutMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxToxFrameProto::onAboutItemClick ) );
}

wxToxFrameProto::~wxToxFrameProto()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxToxFrameProto::onSettingsItemClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxToxFrameProto::onExitItemClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxToxFrameProto::onAddFriendItemClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxToxFrameProto::onOnlineStatusSelect ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxToxFrameProto::onAwayStatusSelect ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxToxFrameProto::onBusyStatusSelect ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxToxFrameProto::onOfflineStatusSelect ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxToxFrameProto::onAboutItemClick ) );
	
}

ConvFrameProto::ConvFrameProto( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	convMenuBar = new wxMenuBar( 0 );
	convFileMenu = new wxMenu();
	wxMenuItem* convCloseMenuItem;
	convCloseMenuItem = new wxMenuItem( convFileMenu, wxID_ANY, wxString( wxT("Close") ) , wxEmptyString, wxITEM_NORMAL );
	convFileMenu->Append( convCloseMenuItem );
	
	convMenuBar->Append( convFileMenu, wxT("File") ); 
	
	this->SetMenuBar( convMenuBar );
	
	convStatusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	wxBoxSizer* convBaseSizer;
	convBaseSizer = new wxBoxSizer( wxVERTICAL );
	
	convBaseSplitter = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	convBaseSplitter->Connect( wxEVT_IDLE, wxIdleEventHandler( ConvFrameProto::convBaseSplitterOnIdle ), NULL, this );
	
	convTopPanel = new wxPanel( convBaseSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* convTopSizer;
	convTopSizer = new wxFlexGridSizer( 1, 1, 0, 0 );
	convTopSizer->AddGrowableCol( 0 );
	convTopSizer->AddGrowableRow( 0 );
	convTopSizer->SetFlexibleDirection( wxBOTH );
	convTopSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	convHtmlWindow = new wxHtmlWindow( convTopPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO|wxNO_BORDER );
	convTopSizer->Add( convHtmlWindow, 0, wxALL|wxEXPAND, 0 );
	
	
	convTopPanel->SetSizer( convTopSizer );
	convTopPanel->Layout();
	convTopSizer->Fit( convTopPanel );
	convBottomPanel = new wxPanel( convBaseSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* convBottomSizer;
	convBottomSizer = new wxFlexGridSizer( 1, 1, 0, 0 );
	convBottomSizer->AddGrowableCol( 0 );
	convBottomSizer->AddGrowableRow( 0 );
	convBottomSizer->SetFlexibleDirection( wxBOTH );
	convBottomSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	convMessageField = new wxTextCtrl( convBottomPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_AUTO_URL|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_PROCESS_ENTER|wxTE_WORDWRAP|wxNO_BORDER );
	convBottomSizer->Add( convMessageField, 0, wxALL|wxEXPAND, 0 );
	
	
	convBottomPanel->SetSizer( convBottomSizer );
	convBottomPanel->Layout();
	convBottomSizer->Fit( convBottomPanel );
	convBaseSplitter->SplitHorizontally( convTopPanel, convBottomPanel, 300 );
	convBaseSizer->Add( convBaseSplitter, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( convBaseSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ConvFrameProto::onClose ) );
	convHtmlWindow->Connect( wxEVT_COMMAND_HTML_LINK_CLICKED, wxHtmlLinkEventHandler( ConvFrameProto::onConversationLinkClicked ), NULL, this );
	convMessageField->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( ConvFrameProto::onSendMessage ), NULL, this );
}

ConvFrameProto::~ConvFrameProto()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ConvFrameProto::onClose ) );
	convHtmlWindow->Disconnect( wxEVT_COMMAND_HTML_LINK_CLICKED, wxHtmlLinkEventHandler( ConvFrameProto::onConversationLinkClicked ), NULL, this );
	convMessageField->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( ConvFrameProto::onSendMessage ), NULL, this );
	
}

SettingsDialogProto::SettingsDialogProto( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* settingsBaseSizer;
	settingsBaseSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	settingsBaseSizer->AddGrowableCol( 0 );
	settingsBaseSizer->AddGrowableRow( 0 );
	settingsBaseSizer->SetFlexibleDirection( wxBOTH );
	settingsBaseSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	settingsBasePanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* settingsIntSizer;
	settingsIntSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	settingsIntSizer->AddGrowableCol( 0 );
	settingsIntSizer->AddGrowableRow( 0 );
	settingsIntSizer->AddGrowableRow( 1 );
	settingsIntSizer->SetFlexibleDirection( wxBOTH );
	settingsIntSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* settingsUserinfoExtSizer;
	settingsUserinfoExtSizer = new wxStaticBoxSizer( new wxStaticBox( settingsBasePanel, wxID_ANY, wxT("User") ), wxVERTICAL );
	
	wxFlexGridSizer* settingsUserinfoIntSizer;
	settingsUserinfoIntSizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	settingsUserinfoIntSizer->AddGrowableCol( 1 );
	settingsUserinfoIntSizer->AddGrowableRow( 0 );
	settingsUserinfoIntSizer->SetFlexibleDirection( wxBOTH );
	settingsUserinfoIntSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	avatarBitmap = new wxStaticBitmap( settingsBasePanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 128,128 ), wxSTATIC_BORDER );
	avatarBitmap->SetForegroundColour( wxColour( 255, 255, 255 ) );
	avatarBitmap->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	
	settingsUserinfoIntSizer->Add( avatarBitmap, 0, wxALL, 5 );
	
	wxFlexGridSizer* fgSizer13;
	fgSizer13 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer13->AddGrowableCol( 1 );
	fgSizer13->AddGrowableRow( 2 );
	fgSizer13->SetFlexibleDirection( wxBOTH );
	fgSizer13->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	nickLabel = new wxStaticText( settingsBasePanel, wxID_ANY, wxT("Nickname"), wxDefaultPosition, wxDefaultSize, 0 );
	nickLabel->Wrap( -1 );
	fgSizer13->Add( nickLabel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	nickField = new wxTextCtrl( settingsBasePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxSIMPLE_BORDER );
	nickField->SetMaxLength( 128 ); 
	fgSizer13->Add( nickField, 0, wxALL|wxEXPAND, 5 );
	
	userKeyLabel = new wxStaticText( settingsBasePanel, wxID_ANY, wxT("User key"), wxDefaultPosition, wxDefaultSize, 0 );
	userKeyLabel->Wrap( -1 );
	fgSizer13->Add( userKeyLabel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	userKeyField = new wxTextCtrl( settingsBasePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	fgSizer13->Add( userKeyField, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	statusTextLabel = new wxStaticText( settingsBasePanel, wxID_ANY, wxT("Statustext"), wxDefaultPosition, wxDefaultSize, 0 );
	statusTextLabel->Wrap( -1 );
	fgSizer13->Add( statusTextLabel, 0, wxALL, 5 );
	
	statusTextField = new wxTextCtrl( settingsBasePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_WORDWRAP|wxSIMPLE_BORDER );
	statusTextField->SetMaxLength( 1007 ); 
	fgSizer13->Add( statusTextField, 0, wxALL|wxEXPAND, 5 );
	
	
	settingsUserinfoIntSizer->Add( fgSizer13, 1, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	settingsUserinfoExtSizer->Add( settingsUserinfoIntSizer, 1, wxEXPAND, 5 );
	
	
	settingsIntSizer->Add( settingsUserinfoExtSizer, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* settingsFiletransferExtSizer;
	settingsFiletransferExtSizer = new wxStaticBoxSizer( new wxStaticBox( settingsBasePanel, wxID_ANY, wxT("Files") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer14;
	fgSizer14 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer14->AddGrowableCol( 1 );
	fgSizer14->SetFlexibleDirection( wxBOTH );
	fgSizer14->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fileDirectoryLabel = new wxStaticText( settingsBasePanel, wxID_ANY, wxT("Files directory"), wxDefaultPosition, wxDefaultSize, 0 );
	fileDirectoryLabel->Wrap( -1 );
	fgSizer14->Add( fileDirectoryLabel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	fileDirectoryField = new wxTextCtrl( settingsBasePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxSIMPLE_BORDER );
	fgSizer14->Add( fileDirectoryField, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer14->Add( 0, 0, 1, wxEXPAND, 5 );
	
	fileAutosaveField = new wxCheckBox( settingsBasePanel, wxID_ANY, wxT("Accept all transfers automatically"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer14->Add( fileAutosaveField, 0, wxALL, 5 );
	
	
	settingsFiletransferExtSizer->Add( fgSizer14, 1, wxEXPAND, 5 );
	
	
	settingsIntSizer->Add( settingsFiletransferExtSizer, 1, wxEXPAND, 5 );
	
	
	settingsBasePanel->SetSizer( settingsIntSizer );
	settingsBasePanel->Layout();
	settingsIntSizer->Fit( settingsBasePanel );
	settingsBaseSizer->Add( settingsBasePanel, 1, wxALL|wxEXPAND, 5 );
	
	settingsDialogButtons = new wxStdDialogButtonSizer();
	settingsDialogButtonsOK = new wxButton( this, wxID_OK );
	settingsDialogButtons->AddButton( settingsDialogButtonsOK );
	settingsDialogButtonsCancel = new wxButton( this, wxID_CANCEL );
	settingsDialogButtons->AddButton( settingsDialogButtonsCancel );
	settingsDialogButtons->Realize();
	
	settingsBaseSizer->Add( settingsDialogButtons, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( settingsBaseSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	nickField->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SettingsDialogProto::onNickChange ), NULL, this );
	statusTextField->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SettingsDialogProto::onStatusTextChange ), NULL, this );
}

SettingsDialogProto::~SettingsDialogProto()
{
	// Disconnect Events
	nickField->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SettingsDialogProto::onNickChange ), NULL, this );
	statusTextField->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SettingsDialogProto::onStatusTextChange ), NULL, this );
	
}

AddFriendDialogProto::AddFriendDialogProto( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* addFiendBaseSizer;
	addFiendBaseSizer = new wxFlexGridSizer( 0, 1, 0, 0 );
	addFiendBaseSizer->AddGrowableCol( 0 );
	addFiendBaseSizer->AddGrowableRow( 0 );
	addFiendBaseSizer->SetFlexibleDirection( wxBOTH );
	addFiendBaseSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	addFriendBasePanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* addFriendSortSizer;
	addFriendSortSizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	addFriendSortSizer->AddGrowableCol( 1 );
	addFriendSortSizer->AddGrowableRow( 1 );
	addFriendSortSizer->SetFlexibleDirection( wxBOTH );
	addFriendSortSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	userKeyLabel = new wxStaticText( addFriendBasePanel, wxID_ANY, wxT("User key"), wxDefaultPosition, wxDefaultSize, 0 );
	userKeyLabel->Wrap( -1 );
	addFriendSortSizer->Add( userKeyLabel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	userKeyField = new wxTextCtrl( addFriendBasePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxSIMPLE_BORDER );
	addFriendSortSizer->Add( userKeyField, 0, wxALL|wxEXPAND, 5 );
	
	userMessageLabel = new wxStaticText( addFriendBasePanel, wxID_ANY, wxT("Message"), wxDefaultPosition, wxDefaultSize, 0 );
	userMessageLabel->Wrap( -1 );
	addFriendSortSizer->Add( userMessageLabel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	userMessageField = new wxTextCtrl( addFriendBasePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_WORDWRAP|wxSIMPLE_BORDER );
	addFriendSortSizer->Add( userMessageField, 0, wxALL|wxEXPAND, 5 );
	
	
	addFriendBasePanel->SetSizer( addFriendSortSizer );
	addFriendBasePanel->Layout();
	addFriendSortSizer->Fit( addFriendBasePanel );
	addFiendBaseSizer->Add( addFriendBasePanel, 1, wxEXPAND | wxALL, 5 );
	
	addFriendDialogButtons = new wxStdDialogButtonSizer();
	addFriendDialogButtonsOK = new wxButton( this, wxID_OK );
	addFriendDialogButtons->AddButton( addFriendDialogButtonsOK );
	addFriendDialogButtonsCancel = new wxButton( this, wxID_CANCEL );
	addFriendDialogButtons->AddButton( addFriendDialogButtonsCancel );
	addFriendDialogButtons->Realize();
	
	addFiendBaseSizer->Add( addFriendDialogButtons, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( addFiendBaseSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
}

AddFriendDialogProto::~AddFriendDialogProto()
{
}
