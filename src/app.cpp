#include "app.h"
#include "wxtoxframe.h"

IMPLEMENT_APP(wxToxApp);

bool wxToxApp::OnInit() {
    wxToxFrame* frame = new wxToxFrame(0L);
    frame->Show();
    return true;
}
