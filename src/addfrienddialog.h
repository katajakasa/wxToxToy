#ifndef _ADDFRIENDDIALOG_H
#define _ADDFRIENDDIALOG_H

#include "wxtoxgui.h"
#include "wxtoxtick.h"

class AddFriendDialog : public AddFriendDialogProto {
protected:
    wxToxTick *m_tox;

public:
    AddFriendDialog(wxWindow* parent, wxToxTick *tox);
    ~AddFriendDialog();

    void save();
};

#endif // _ADDFRIENDDIALOG_H
