#define OLC_PGE_APPLICATION
#include "Headers/Graphical Control Unit/olcPixelGameEngine.h"
#include "Headers/Graphical Control Unit/GCU.h"
#include "Headers/Graphical Control Unit/DataTypes/TextInput.h"
#include "Headers/Graphical Control Unit/DataTypes/ListDisc.h"
#include <string>
#include <iostream>
int st = 0;
int gamestate = 1;
bool update = 1;
GCU *GControl;
int Index[3] = {-1,-1,-1};
bool st1=0;
int SelectedOption = -1;
int ScrollOffset = 0;
class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Task Manager 2.0";
	}

public:
	bool OnUserCreate() override
	{
		GControl = new GCU(this);
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		if (update) {
			update = 0;
			//Needed for all windows
			Clear(olc::Pixel(255, 255, 255));
			olc::PixelGameEngine::DrawRect(0, 0, 75, 20, olc::GREY);
			olc::PixelGameEngine::DrawRect(75, 0, 75, 20, olc::GREY);
			olc::PixelGameEngine::DrawRect(150, 0, 37, 20, olc::GREY);
			olc::PixelGameEngine::DrawRect(187, 0, 37, 20, olc::GREY);
			olc::PixelGameEngine::DrawRect(224, 0, 37, 20, olc::GREY);
			olc::PixelGameEngine::DrawRect(261, 0, 39, 20, olc::GREY);
			//mode spefic static objects
			switch (gamestate) {
			case 1:
				break;
			case 2:
				break;
			}
		}
		update = GControl->st[1];
		GControl->menuOptions(Index);
		if (!GControl->st[0]) {
			olc::PixelGameEngine::DrawStringDecal({ 5,7 }, "Load Database", olc::GREY, { {0.6} ,{0.75} });
			olc::PixelGameEngine::DrawStringDecal({ 80,7 }, "Save Database", olc::GREY, { {0.6} ,{0.75} });
			olc::PixelGameEngine::DrawStringDecal({ 162,7 }, "Add", olc::GREY, { {0.6} ,{0.75} });
			olc::PixelGameEngine::DrawStringDecal({ 197,7 }, "Edit", olc::GREY, { {0.6} ,{0.75} });
			olc::PixelGameEngine::DrawStringDecal({ 197+32,7 }, "Delete", olc::GREY, { {0.6} ,{0.75} });
			olc::PixelGameEngine::DrawStringDecal({ 197 + 72,7 }, "Help", olc::GREY, { {0.6} ,{0.75} });
			switch (gamestate) {
			case 1:
				if (listProjects(20, 75, 0, "Projects", this, &GControl->myDat,&SelectedOption) != -1) {
					Index[0] = listProjects(20, 75, 0, "Projects", this, &GControl->myDat,&SelectedOption);
				}
				break;
			case 2:
				break;
			}
			//TODO add scrolling functionality or move it to the gcu
			if (GetKey(olc::DOWN).bPressed) {
				ScrollOffset++;
			}
			if (GetKey(olc::UP).bPressed) {
				ScrollOffset--;
			}
			if (GetMouse(0).bPressed) {
				if (GetMouseX() > 200&&GetMouseY()<200&&GetMouseY()>40) {
					Index[gamestate - 1] = -1;
					SelectedOption = -1;
				}
				if (GetMouseY() > 200) {
					if (GetMouseX() < 150) {
						gamestate--;
					}
					else {
						gamestate++;
					}
					update = 1;
				}
			}
			//if (GetKey(olc::LEFT).bPressed) {
//
			//}
			//if (GetKey(olc::ENTER).bPressed) {
			//
			//}
		}
		return true;
	}
};
int main()
{
	Example demo;
	if (demo.Construct(300, 300, 2, 2))
		demo.Start();
	return 0;
}
