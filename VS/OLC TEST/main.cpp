#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <iostream>
std::string gamestate;
struct sprobj {
	float x;
	float y;
	float anitimer;
	float speed;
	int CurAniFrame;
	bool aniUpdate;
	std::string AniDir[10][10];
	float actTimer;
	void ani(int curState,int frameDur,int totFrames, float timer) {
		if (this->aniUpdate) {
			if (this->anitimer > frameDur) { this->anitimer = 0; this->CurAniFrame++; }
			else { this->anitimer = this->anitimer + (100 * timer); }
			if (this->CurAniFrame == totFrames) { this->CurAniFrame = 0; }
		}
	}
};
sprobj gomb;
	// Override base class with your custom functionality
	class Example : public olc::PixelGameEngine
	{
	public:
		Example()
		{
			sAppName = "Matthew's Program";
		}
	public:
		bool OnUserCreate() override
		{
			// Called once at the start, so create things here
			gomb.AniDir[0][0] = "C://Users/mener/OneDrive/Documents/GitHub/CppPrograms/VS/OLC TEST/Goomba1.png";
			gomb.AniDir[0][1] = "C://Users/mener/OneDrive/Documents/GitHub/CppPrograms/VS/OLC TEST/Goomba2.png";
			gamestate = "title";
			gomb.y = ScreenHeight() - 41;
			gomb.speed = 200;
			SetPixelMode(olc::Pixel::ALPHA);
			Clear(olc::Pixel(0, 0, 255));
			return true;
		}
		bool OnUserUpdate(float fElapsedTime) override
		{
			//Sleep(1000 / 70);

			if (gamestate == "Play") {
				Clear(olc::Pixel(100, 100, 100));
				if (GetKey(olc::Key::LEFT).bHeld) { gomb.x = gomb.x - (gomb.speed * fElapsedTime);  }
				if (GetKey(olc::Key::RIGHT).bHeld) { gomb.x = gomb.x + (gomb.speed * fElapsedTime);}
				if (GetKey(olc::Key::UP).bHeld) { gomb.y = gomb.y - (gomb.speed* fElapsedTime);  }
				if (GetKey(olc::Key::DOWN).bHeld) { gomb.y = gomb.y + (gomb.speed * fElapsedTime); }
				//if (GetKey(olc::Key::LEFT).bReleased) { gomb.aniUpdate = false; }
				//if (GetKey(olc::Key::RIGHT).bReleased) { gomb.aniUpdate = false; }
				//gomb.ani(0,25,2,fElapsedTime);
				//std::string dir = gomb.AniDir[0][gomb.CurAniFrame];
				//olc::Sprite p = olc::Sprite::Sprite(dir);
				olc::PixelGameEngine::FillRect(gomb.x, gomb.y, 40, 40,olc::Pixel(255,0,255));
			}
			if (gamestate == "title") {
				olc::PixelGameEngine::DrawString(20, 20, "Press Enter To PLay!", olc::Pixel::Pixel(20, 20, 20),2);
				if (GetKey(olc::Key::ENTER).bHeld)
				{
					gamestate = "Play";
				}
			}
			return true;
			
		}
	};
	int main()
	{
		Example demo;
		if (demo.Construct(500, 500, 1, 1))
			demo.Start();
		return 0;
	}
