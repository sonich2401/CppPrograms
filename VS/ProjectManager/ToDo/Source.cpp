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
		std::string input, message;
		int x, y, width, height,R,G,B,_R,_G,_B;
		void setForm(int X, int Y, int Width, int Height, int r,int g,int b, int _r,int _g,int _b, std::string dstr = "Form") {
			x = X;
			y = Y;
			R = r;
			G = g;
			B = b;
			_R = _r;
			_G = g;
			_B = b;
			width = Width;
			height = Height;
			message = dstr;
		}
	};
	struct page {
		//buttons
		button addButt[100];
		bool buttonDown(olc::PixelGameEngine* pge,int buttonId) {
			int x = pge->GetMouseX();
			int y = pge->GetMouseY();
			if (x > addButt[buttonId].x && x < addButt[buttonId].width+10 && y > addButt[buttonId].y && y < addButt[buttonId].height + 10 && pge->GetMouse(0).bHeld) {
				return 1;
			}
			else { return 0; }
		}
		int max=0;
		void addButton(int X, int Y, int Width, int Height, std::string buttonText) {
		addButt[max].buttonset(X,Y,Width,Height,buttonText);
		max++;
		}
		//forms
		form formin[100];
		int max2;
		page() {
			max2 = 0;
		}
		int curForm=0;
		void addForm(int X, int Y, int Width, int Height, int r, int g, int b, int _r, int _g, int _b, std::string dstr = "Form") {
			formin[max2].setForm(X,Y,Width,Height,r,g,b,_r,_g,_b,dstr);
			max2++;
		}
		int formSel(olc::PixelGameEngine* pge) {
			int x = pge->GetMouseX();
			int y = pge->GetMouseY();
			for (int formId = 0; formId < max2; formId++) {
				if (x > formin[formId].x && x < formin[formId].width + 10 && y > formin[formId].y&& y < formin[formId].height + 10 && pge->GetMouse(0).bHeld) {
					curForm = formId;
					return formId;
				}
				else { return -1; }
			}
		}
		int formM() {
			return curForm;
		}
		//update screen
		void drawPage(olc::PixelGameEngine* pge) {
			//Buttons
			for (int i = 0; i < max; i++) {
				pge->DrawRect(addButt[i].x, addButt[i].y, addButt[i].width, addButt[i].height,olc::BLACK);
				pge->DrawString(addButt[i].x,addButt[i].y,addButt[i].buttonText,olc::GREY);
			}
			//forms
			std::cout << max2;
			for (int i = 0; i < max2; i++) {
				pge->DrawRect(formin[i].x, formin[i].y, formin[i].width, formin[i].height, olc::Pixel(formin[i].R, formin[i].G, formin[i].B));
				pge->DrawString(formin[i].x, formin[i].y, formin[i].message, olc::GREY);
			}
		}
	};

	bool st, st2;
	int mainSt;
	char input[32];
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
		mainSt = 1;
		st = 0;
		st2 = 0;
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
		page mainpage;
		page addProject;
		//page addProject;
		int tmp;
		switch (mainSt) {
		 case 1:
			 st = 1;
			mainpage.addButton(10, 10, 60, 25, "Add\nProject");
			mainpage.addButton(80, 10, 60, 25, "Delete\nProject");
			if (st) {st = 0; mainpage.drawPage(this);}
			if (mainpage.buttonDown(this, 0)) {
				mainSt = 2;
				st = 0;
				st2 = 1;
				Clear(olc::Pixel(255,255,255));
			}
			break;
		case 2:
			char tmpo;
			if (st2) { st2 = 0;  addProject.addForm(10, 100, 100, 70, 0, 0, 0, 0, 0, 0, "Default"); }
				if (GetKey(olc::Key::A).bPressed) { tmpo = 'a'; }
				if (GetKey(olc::Key::B).bPressed) { tmpo = 'b'; }
				if (GetKey(olc::Key::C).bPressed) { tmpo = 'c'; }
				if (GetKey(olc::Key::D).bPressed) { tmpo = 'd'; }
				if (GetKey(olc::Key::E).bPressed) { tmpo = 'e'; }
				if (GetKey(olc::Key::F).bPressed) { tmpo = 'f'; }
				if (GetKey(olc::Key::G).bPressed) { tmpo = 'g'; }
				if (GetKey(olc::Key::H).bPressed) { tmpo = 'h'; }
				if (GetKey(olc::Key::I).bPressed) { tmpo = 'i'; }
				if (GetKey(olc::Key::J).bPressed) { tmpo = 'j'; }
				if (GetKey(olc::Key::K).bPressed) { tmpo = 'k'; }
				if (GetKey(olc::Key::L).bPressed) { tmpo = 'l'; }
				if (GetKey(olc::Key::M).bPressed) { tmpo = 'm'; }
				if (GetKey(olc::Key::N).bPressed) { tmpo = 'n'; }
				if (GetKey(olc::Key::O).bPressed) { tmpo = 'o'; }
				if (GetKey(olc::Key::P).bPressed) { tmpo = 'p'; }
				if (GetKey(olc::Key::Q).bPressed) { tmpo = 'q'; }
				if (GetKey(olc::Key::R).bPressed) { tmpo = 'r'; }
				if (GetKey(olc::Key::S).bPressed) { tmpo = 's'; }
				if (GetKey(olc::Key::T).bPressed) { tmpo = 't'; }
				if (GetKey(olc::Key::U).bPressed) { tmpo = 'u'; }
				if (GetKey(olc::Key::V).bPressed) { tmpo = 'v'; }
				if (GetKey(olc::Key::W).bPressed) { tmpo = 'w'; }
				if (GetKey(olc::Key::X).bPressed) { tmpo = 'x'; }
				if (GetKey(olc::Key::Y).bPressed) { tmpo = 'y'; }
				if (GetKey(olc::Key::Z).bPressed) { tmpo = 'z'; }
				addProject.formin[0].message.push_back(tmpo);
				Clear(olc::Pixel(255, 255, 255));
				addProject.drawPage(this);
				/*olc::PixelGameEngine::DrawRect(10, 40, 100, 70, olc::Pixel(0, 0, 0));
				olc::PixelGameEngine::DrawString(12, 42, "My Project", olc::Pixel(100, 100, 100));*/
			break;
		case 3:
			break;
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