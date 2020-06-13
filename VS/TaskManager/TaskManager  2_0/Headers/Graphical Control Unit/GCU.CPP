#include "GCU.h"
int GCU::GlobalButtonCheck()
{
	if (pge->GetMouse(0).bPressed) {
		if (pge->GetMouseY() < 20) {
			int mx= pge->GetMouseX();
			if (mx > 0 && mx < 75) {
				return 0;
			}
			if (mx > 75 && mx < 75*2) {
				return 1;
			}
			if (mx > (75*2)+37 && mx < 75*2) {
				return 2;
			}
			if (mx > (75 * 2)+(37) && mx < (75 *2)+(37*2)) {
				return 3;
			}
			if (mx > (75 * 2) + (37*2) && mx < (75 * 2) + (37 * 3)) {
				return 4;
			}
			if (mx > (75 * 2) + (37 * 3) && mx < (75 * 2) + (37 * 4)) {
				return 5;
			}
		}
	}
	return -1;
}

void GCU::menuOptions(int Index[3])
{
	pUpdate = 0;
	if (this->GlobalButtonCheck() != -1 && menuMode == -1) {
		menuMode = this->GlobalButtonCheck();
	}
		switch (menuMode) {
		case 0:
			//TODO Load Database
			if (this->GlobalButtonCheck()==0) {
				myDat.loadDatabase();
				MessageBox(NULL, L"Databse Loaded Successfully!", L"Database Load", MB_OK);
				menuMode = -1;
			}
			break;
		case 1:
			//TODO Save Database
			if (this->GlobalButtonCheck()==1) {
				MessageBox(NULL, L"Please Make Sure the File Name You Enter Ends with .pds", L"Database Save", MB_OK);
				myDat.saveDatabase();
				MessageBox(NULL, L"Databse Saved Successfully!", L"Database Export", MB_OK);
				menuMode = -1;
			}
			break;
		case 2:
			//TODO [std::string title]  add
			overide = 1;
			if (Index[0] != -1) {
				if (Index[1] != -1) {
					if (Index[2] == -1) {
						//Add Task
						AddTaskMenu(Index[0],Index[1]);
					}
				}
				else {
					//Add Region
					AddRegionMenu(Index[0]);
				}
			}
			else {
				//Add Project
				AddProjectMenu();
			}
			break;
		case 3:
			overide = 1;
			//TODO [std::string title]  edit
			if (Index[0] != -1) {
				if (Index[1] != -1) {
					if (Index[2] == -1) {
						//Edit Region
						EditRegionMenu(Index[0],Index[1]);
					}
					else {
						//Edit Task
						EditTaskMenu(Index);
					}
				}
				else {
					//EditProject
					EditProjectMenu(Index[0]);
				}
			}
			break;
		case 4:
			overide = 1;
			//TODO [std::string title]  edit
			if (Index[0] != -1) {
				if (Index[1] != -1) {
					if (Index[2] == -1) {
						//Edit Region
						DeleteRegionMenu(Index[0],Index[1]);
					}
					else {
						//Edit Task
						DeleteTaskMenu(Index);
					}
				}
				else {
					//EditProject
					DeleteProjectMenu(Index[0]);
				}
			}
			break;
		case 5:
			overide = 1;
			//TODO Help
			break;

		}
}

GCU::GCU(olc::PixelGameEngine* _pge) {
	pge = _pge;
	MenuOptionsAcivationState = 1;
}