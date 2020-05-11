#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <iostream>
#include <fstream>
#include <string>
#include "sb.h"
#include "Forms.h"
//#include <bits/stdc++.h>
	struct button {
		int width;
		int height;
		int x;
		int y;
		std::string buttonText;
		button(int _x = 0, int _y = 0, int _width = 50, int _height = 25, std::string _buttonText = "Button") {
			width = _width;
			height = _height;
			x = _x;
			y = _y;
			buttonText = _buttonText;
		}
		void buttonset(int _x = 0, int _y = 0, int _width = 50, int _height = 25, std::string _buttonText = "Button") {
			width = _width;
			height = _height;
			x = _x;
			y = _y;
			buttonText = _buttonText;
		}
	};
	struct form {

	};
	struct page {
		button addButt[100];
		bool buttonDown(olc::PixelGameEngine* pge,int buttonId) {
			int x = pge->GetMouseX();
			int y = pge->GetMouseY();
			if (x > addButt[buttonId].x && x < addButt[buttonId].width+10 && y > addButt[buttonId].y && y < addButt[buttonId].height + 10 && pge->GetMouse(0).bHeld) {
				return 1;
			}
			else { return 0; }
		}
		int max;
		page() {
			max=0;
		}
		void addButton(int X, int Y, int Width, int Height, std::string buttonText) {
		addButt[max].buttonset(X,Y,Width,Height,buttonText);
		max++;
		}
		void drawPage(olc::PixelGameEngine* pge) {
			for (int i = 0; i < max; i++) {
				pge->DrawRect(addButt[i].x, addButt[i].y, addButt[i].width, addButt[i].height,olc::BLACK);
				pge->DrawString(addButt[i].x,addButt[i].y,addButt[i].buttonText,olc::GREY);

			}
		}
	};



class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Matthew";
	}

public:
	bool OnUserCreate() override
	{
		Clear(olc::Pixel(255, 255, 255));
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		if (GetKey(olc::Key::ENTER).bHeld) {
			std::cout << sb::readline("a.txt", 2);
		}
		if (GetKey(olc::Key::ESCAPE).bHeld) {
			sb::writeLine(2,"Death","a.txt");
		}
		int mx = olc::PixelGameEngine::GetMouseX();
		int my = olc::PixelGameEngine::GetMouseY();
		page mainpage;
		mainpage.addButton(10,10,60,25,"Add\nProject");
		mainpage.addButton(80, 10, 60, 25, "Delete\nProject");
		mainpage.drawPage(this);
		if (mainpage.buttonDown(this, 0)) {
			std::cout << rand() % 100<<"\n";
		}
		return true;
	}
};

int main()
{
	Example demo;
	if (demo.Construct(250, 250, 1, 1))
		demo.Start();
	return 0;
}