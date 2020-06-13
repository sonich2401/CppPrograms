#pragma once
#include "wx/wx.h"
#include <wx/treectrl.h>
#include "../Task Manager/Headers/DatabaseControl/Database.h"
//#include "../Task Manager/Headers/Utility/sb.h"
#include <string>
class cMain : public wxFrame
{
public:
	cMain();
	~cMain();
public:
	database myDat;
	//TopMenu
	wxMenuBar* TopMenuBar = nullptr;
	//File Menu
		wxMenu* FileDropDown = nullptr;
			std::string name;
			wxMenuItem* SaveMenu = nullptr;
			wxMenuItem* LoadDbMenu = nullptr;
	//Credits Menu
		wxMenu* CreditsTab = nullptr;
			wxMenuItem* CreditsMenu = nullptr;

	//wxBoxSizer* bSizer2=nullptr;
	wxTreeCtrl* DatabaseVeiw;
	
public:
	void OnButtonClicked(wxCommandEvent &evt);
	void SaveHit(wxCommandEvent& event);
	void LoadHit(wxCommandEvent& event);
	void showCredits(wxCommandEvent& event);
public:
	wxDECLARE_EVENT_TABLE();
};

