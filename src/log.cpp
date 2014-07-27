#include "log.h"

static wxHtmlWindow* _logHtmlPanel = 0;

void log_init(wxHtmlWindow* panel) {
    _logHtmlPanel = panel;
}

void log_add(wxString text) {
    if(_logHtmlPanel) {
        wxString m;
        m << text << "<br />";
        _logHtmlPanel->AppendToPage(m);
    }
}