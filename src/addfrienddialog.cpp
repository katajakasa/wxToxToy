#include "addfrienddialog.h"


AddFriendDialog::AddFriendDialog(wxWindow* parent, wxToxTick *tox) : AddFriendDialogProto(parent) {
    m_tox = tox;
}

AddFriendDialog::~AddFriendDialog() {

}

void AddFriendDialog::save() {
    m_tox->addFriend(userKeyField->GetValue(), userMessageField->GetValue());
}