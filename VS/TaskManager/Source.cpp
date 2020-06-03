#define OLC_PGE_APPLICATION
#include <iostream>
#define endl "\n"
#include "utilFunc.h"
#include "olcPixelGameEngine.h"
#include "SourceHeader.h" 
fakeclass sbh;
unsigned int gamestate=1;
string currentModeTitle;
bool update=0;
unsigned int bIndex[3] = {0,0,0};
unsigned int returnGamestate;
/*void conHelp(olc::PixelGameEngine* pge, float x, float y, int b = -1,  int b1 = -1, int b2 = -1) {
	int mode=1;
	if (b == -1) {
		b = 0;
	}
	if (b1 == -1) {
		b1 = 0;
	}
	if (b != -1 && b1 != -1 &&b2 ==-1) {
		b2 = 0;
		mode = 2;
	}
	if (b != -1 && b1 != -1 && b2 != -1) {
		mode = 3;
	}
	const unsigned int sizes[3] = { sbh.data.ProjectDatabase.size(),sbh.data.ProjectDatabase[b].projectDat.size(),sbh.data.ProjectDatabase[b].projectDat[b1].tasks.size() };
	for (unsigned int i = 0; i < sizes[mode-1]; i++) {
		int tmpint = i;
		olc::vi2d pos = { 22,22 + (tmpint * 26) };
		if (x > pos.x&& x < pos.x + 71 && y>pos.y&& y < pos.y + 25) {
			bIndex[mode-1] = mode;
			switch (mode) {
			case 1:
				sbh.discription(100, 20, sbh.data.ProjectDatabase[i]);
				break;
			case 2:
				sbh.discription(100, 20, sbh.data.ProjectDatabase[b].projectDat[i]);
				break;
			case 3:
				sbh.discription(100, 20, sbh.data.ProjectDatabase[b].projectDat[b1].tasks[i]);
				break;
			//case 3:
			//	sbh.discription(100,20,sbh.data.ProjectDatabase[b].projectDat[b1].tasks)
			//	break;
				//sbh.discription(100, 20, sbh.data.ProjectDatabase[i]);
			}
			if (pge->GetMouse(0).bPressed) {
				gamestate = mode-1;
				update = 1;
			}
		}
		else {
			pge->FillRect({ 100,20 }, { 181,140 });
		}
	}
}
*/
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

int menuCollision(olc::PixelGameEngine *pge,float mx,float my) {
	if (pge->GetMouse(0).bPressed) {
		for (int i = 0; i < 3; i++) {
			if (mx > 20 + (i * 90) && mx < 95 + (i * 90) && my > 250) {
				return i;
			}
		}
	}
	else { return -1; }
}

template <class U>
void options(olc::PixelGameEngine* pge, U obj) {//TODO FINSISH THIS FUNCTION
	//TODO FINSISH THIS FUNCTION
} //TODO FINSISH THIS FUNCTION

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
				trayMenu(this, 250, 0);
				break;
			case 2:
				sbh.listRegion(20, 20, 0, "Groupings", bIndex[0]);
				trayMenu(this, 250, 1);
				break;
			case 3:
				sbh.listTasks(20, 20, "Tasks", bIndex[0],bIndex[1]);
				trayMenu(this, 250, 2);
				break;
			case 4:
				sbh.taskVeiw(bIndex[0], bIndex[1], bIndex[2]);
				//trayMenu(this, 250, 0);
				break;
			default:
				gamestate = 1;
			}
		}
		float mx = GetMouseX();
		float my = GetMouseY();
		int sel=menuCollision(this, mx, my);
		switch (gamestate) {
			case 1:
				for (unsigned int i = 0; i < sbh.data.Dat.size(); i++) {
					int tmpint = i;
					olc::vi2d pos = { 22,22 + (tmpint * 26) };
					if (mx > pos.x&& mx < pos.x + 71 && my>pos.y&& my < pos.y + 25) {
						bIndex[0] = i;
						sbh.discription(100, 20, sbh.data.Dat[i]);
						sbh.drawTime(&sbh.data.Dat[i].created, 0);
						sbh.drawTime(&sbh.data.Dat[i].modified, 1);
						if (GetMouse(0).bPressed) {
							gamestate = 2;
							update = 1;
						}
					}
					else {
						olc::PixelGameEngine::FillRect({ 101,31 }, { 170,100 });
						olc::PixelGameEngine::FillRect({ 20,210 }, { 300,30 }, olc::WHITE);
					}
				}
				/*if (sel != -1) {
					returnGamestate = 1;
					gamestate = 5;
					update = 1;
				}*/
				break;
			case 2:
				for (unsigned int i = 0; i < sbh.data.Dat[bIndex[0]].Dat.size(); i++) {
					int tmpint = i;
					olc::vi2d pos = { 22,22 + (tmpint * 26) };
					if (mx > pos.x&& mx < pos.x + 71 && my>pos.y&& my < pos.y + 25) {
						bIndex[1] = i;
						sbh.discription(100, 20, sbh.data.Dat[bIndex[0]].Dat[i]);
						sbh.drawTime(&sbh.data.Dat[bIndex[0]].Dat[i].created, 0);
						sbh.drawTime(&sbh.data.Dat[bIndex[0]].Dat[i].modified, 1);
						if (GetMouse(0).bPressed) {
							gamestate = 3;
							update = 1;
						}
					}
					else {
						olc::PixelGameEngine::FillRect({ 101,31 }, { 165,100 });
						olc::PixelGameEngine::FillRect({ 20,210 }, { 300,30 });
					}
				}
				break;
			case 3:
				for (unsigned int i = 0; i < sbh.data.Dat[bIndex[0]].Dat[bIndex[1]].Dat.size(); i++) {
					int tmpint = i;
					olc::vi2d pos = { 22,22 + (tmpint * 26) };
					if (mx > pos.x&& mx < pos.x + 71 && my>pos.y&& my < pos.y + 25) {
						bIndex[1] = i;
						sbh.discription(100, 20, sbh.data.Dat[bIndex[0]].Dat[bIndex[1]].Dat[i]);
						sbh.drawTime(&sbh.data.Dat[bIndex[0]].Dat[bIndex[1]].Dat[i].created, 0);
						sbh.drawTime(&sbh.data.Dat[bIndex[0]].Dat[bIndex[1]].Dat[i].modified, 0);
						if (GetMouse(0).bPressed) {
							gamestate = 4;
							update = 1;
						}
					}
					else {
						olc::PixelGameEngine::FillRect({ 101,31 }, { 165,100 });
						olc::PixelGameEngine::FillRect({ 20,210 }, { 300,30 });
					}
				}
				break;
			case 4:
				sbh.discription(100, 20, sbh.data.Dat[bIndex[0]].Dat[bIndex[1]].Dat[bIndex[1]]);
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