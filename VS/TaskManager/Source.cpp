#define OLC_PGE_APPLICATION
#include <iostream>
#define endl "\n"
#include "utilFunc.h"
#include "olcPixelGameEngine.h"
#include "SourceHeader.h" 
fakeclass sbh;
unsigned int gamestate=1;
string currentModeTitle;
string newstr="";
bool update=0;
int sel=0;
bool selst = 0;
unsigned int bIndex[3] = {0,0,0};
unsigned int returnGamestate;
void updat(int val) {
	gamestate = val;
	update = 1;
}
void menuCollision(olc::PixelGameEngine* pge) {
	float my = pge->GetMouseY();
	if (!selst || my>250) {
		float mx = pge->GetMouseX();
		for (int i = 0; i < 3; i++) {
			if (mx > 20 + (i * 90) && mx < 95 + (i * 90) && my > 250) {
				sel = i + 2;
			}
		}
	}
}
template <class U>
void conHelp(olc::PixelGameEngine* pge, U *obj,float mx, float my,short unsigned int mode) {
	bool st = 0;
	for (unsigned int i = 0; i <obj->Dat.size(); i++) {
		int tmpint = i;
		olc::vi2d pos = { 22,22 + (tmpint * 26) };
		if (mx > pos.x&& mx < pos.x + 71 && my>pos.y&& my < pos.y + 25) {
			bIndex[int(mode-1)] = i;
			sbh.discription(100, 20, obj->Dat[i]);
			date c=obj->Dat[i].created;
			date m = obj->Dat[i].modified;
			sbh.drawTime(&c, 0);
			sbh.drawTime(&m, 1);
			st = 1;
			if (pge->GetMouse(0).bPressed) {
				if (sel == 0) {
					updat(mode + 1);
				}
				else {
					returnGamestate = mode;
					updat(sel);
				}
			}
		}
		else {
			if (!st) {
				pge->FillRect({ 101,31 }, { 170,100 });
				pge->FillRect({ 20,210 }, { 300,30 }, olc::WHITE);
			}
		}
	}
}
void trayMenu(olc::PixelGameEngine* pge,float y, int mode) {
	string title[3] = {"Project","Grouping","Task"};
	string option[3] = { "New","Edit","Delete" };
	int _y = int(y);
	pge->DrawRect({ 15,_y }, { 75,25 }, olc::BLACK);
		pge->DrawRect({ 105,_y }, { 75,25 }, olc::BLACK);
		pge->DrawRect({ 195,_y }, { 75,25 }, olc::BLACK);
		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < 3; k++) {
				pge->DrawString({ 20 + (i * 90),_y + 4 }, title[mode], olc::BLACK);
				pge->DrawString({ 20 + (i * 90),_y + 14 }, option[i], olc::BLACK);
			}
		}
}
void textIn() {

}

class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Task Manager";
	}
public:
	bool OnUserCreate() override{
		Clear(olc::WHITE);
		sbh.pge = this;
		sbh.loadData();
		sbh.listProjects(20, 20, 0, "Projects");
		sbh.discription(100, 20, sbh.data.Dat.front());
		trayMenu(this, 250, 0);
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override{
		if (update) {
			Clear(olc::WHITE);
			update = false;
			switch (gamestate) {
			case 1:
				sbh.listProjects(20, 20, 0, "Projects");
				menuCollision(this);
				trayMenu(this, 250, 0);
				break;
			case 2:
				sbh.listRegion(20, 20, 0, "Groupings", bIndex[0]);
				menuCollision(this);
				trayMenu(this, 250, 1);
				break;
			case 3:
				sbh.listTasks(20, 20, "Tasks", bIndex[0],bIndex[1]);
				menuCollision(this);
				trayMenu(this, 250, 2);
				break;
			case 4:
				sbh.taskVeiw(bIndex[0], bIndex[1], bIndex[2]);
				break;
			case 5:
				olc::PixelGameEngine::DrawString(125, 0, "N e w");
				olc::PixelGameEngine::DrawString(130, 6, "______");
					break;

			default:
				gamestate = 1;
			}
		}
		float mx = GetMouseX();
		float my = GetMouseY();
			switch (gamestate) {
			case 1:
				conHelp(this, &sbh.data, mx, my, 1);
				break;
			case 2:
				conHelp(this, &sbh.data.Dat[bIndex[0]], mx, my, 2);
				break;
			case 3:
				conHelp(this, &sbh.data.Dat[bIndex[0]].Dat[bIndex[1]], mx, my, 3);
				break;
			case 4:
				sbh.discription(100, 20, sbh.data.Dat[bIndex[0]].Dat[bIndex[1]].Dat[bIndex[2]]);
				break;
			case 5:
				break;
		}
		if (GetKey(olc::ENTER).bPressed) {
			if (gamestate != 1) {
				if (gamestate == 5) {
					gamestate = returnGamestate;
					update = 1;
				}
				else {
					gamestate--;
					update = 1;
				}
			}
		}
		return true;

	}
};

int main(){
	Example demo;
	if (demo.Construct(300, 300, 2, 2))
		demo.Start();
	return 0;
}