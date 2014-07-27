#include "settingsdialog.h"


SettingsDialog::SettingsDialog(wxWindow* parent, wxToxTick *tox) : SettingsDialogProto(parent) {
    m_tox = tox;
    nickField->SetValue(m_tox->getNick());
    userKeyField->SetValue(m_tox->getKey());
    statusTextField->SetValue(m_tox->getStatusText());
}

SettingsDialog::~SettingsDialog() {

}

void SettingsDialog::save() {
    m_tox->setNick(nickField->GetValue());
    m_tox->setStatusText(statusTextField->GetValue());
}