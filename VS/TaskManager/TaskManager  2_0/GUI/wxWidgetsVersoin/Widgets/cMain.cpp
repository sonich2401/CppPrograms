#include "cMain.h"
#include "MenuItemsDef.h"
#include <string>
#include <deque>
wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_MENU(1002,SaveHit)
EVT_MENU(1003, LoadHit)
EVT_MENU(1004, showCredits)
wxEND_EVENT_TABLE()
cMain::cMain() : wxFrame(nullptr,wxID_ANY,"Task Manager",wxPoint(30,30),wxSize(600,600))
{
	//main menu top Menu bar
	TopMenuBar = new wxMenuBar();
	FileDropDown = new wxMenu();
	SaveMenu = new wxMenuItem(FileDropDown, 1002, "Save Database");
	FileDropDown->Append(SaveMenu);
	LoadDbMenu = new wxMenuItem(FileDropDown, 1003, "Load Database");
	FileDropDown->Append(LoadDbMenu);
	CreditsTab = new wxMenu();
	CreditsMenu = new wxMenuItem(CreditsTab,1004,"Credits");
	CreditsTab->Append(CreditsMenu);
	TopMenuBar->Append(FileDropDown,_("&File"));
	TopMenuBar->Append(CreditsTab, _("&Credits"));
	TopMenuBar->Show();

	//main window
	DatabaseVeiw = new wxTreeCtrl(this, 10006, wxPoint(10, 10), wxSize(300, 500));
	SetMenuBar(TopMenuBar);
	DatabaseVeiw->AddRoot("Main Root",0);
	DatabaseVeiw->Show();
}

cMain::~cMain()
{
}

void cMain::OnButtonClicked(wxCommandEvent& evt)
{

}
void cMain::SaveHit(wxCommandEvent& event) {
	wxFileDialog openf(this,"Save File","","","Project Database Save File (*.pds)|*.pds",wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (openf.ShowModal() != wxCANCEL_DEFAULT) {
		name = openf.GetPath().ToStdString();
		myDat.saveDatabase(name);
		wxMessageBox("Database Save Sucess!", "Database Export", 5L, this);
	}
	event.Skip();
}

void cMain::LoadHit(wxCommandEvent& event)
{
	wxFileDialog openf(this, "Load File", "", "", "Project Database Save File (*.pds)|*.pds", wxFD_OPEN);
	openf.ShowModal();
	name= openf.GetPath().ToStdString();
	myDat.loadDatabase(name);
	wxMessageBox("Database Load Sucess!", "Database Import", 5L, this);
	//TODO Get Rid of all of this code. The loops need to go
	for (unsigned int i = 0; i < myDat.Dat.size(); i++) {
		for (unsigned int i1 = 0; i1 < myDat.Dat[i].Dat.size(); i1++) {
			for (unsigned int i2 = 0; i2 < myDat.Dat[i].Dat[i1].Dat.size(); i2++) {

			}
		}
	}
	DatabaseVeiw->Update();
	event.Skip();
}

void cMain::showCredits(wxCommandEvent& event)
{
	wxMessageBox("Lead Programmer: Rendev\nHello", "Main Team");
	wxMessageBox("Database Programmer: Rendev", "Main Team");
	wxMessageBox("File Structure Programmer: Rendev", "Main Team");
	wxMessageBox("GUI Programmer: Rendev", "Main Team");
	wxMessageBox("Javid9x - For inspiring me to learn C++ and made a tutorial for wxWidgets", "Specail Thanks To . . .");
	wxMessageBox("wxWidgets - For making the visual SDK that this program is visualised with", "Specail Thanks To . . .");
	event.Skip();
}


