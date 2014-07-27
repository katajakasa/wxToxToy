#ifndef _LOG_H
#define _LOG_H

#include <wx/html/htmlwin.h>

void log_init(wxHtmlWindow* panel);
void log_add(wxString text);

#endif // _LOG_H