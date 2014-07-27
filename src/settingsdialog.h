#ifndef _SETTINGSDIALOG_H
#define _SETTINGSDIALOG_H

#include "wxtoxgui.h"
#include "wxtoxtick.h"

class SettingsDialog : public SettingsDialogProto {
protected:
    wxToxTick *m_tox;

public:
    SettingsDialog(wxWindow* parent, wxToxTick *tox);
    ~SettingsDialog();

    void save();
};

#endif // _SETTINGSDIALOG_H
