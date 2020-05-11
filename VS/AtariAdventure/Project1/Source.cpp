#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
//#include "colldata.h"
//#include "func.h"
float x = 30;
float y = 30;
bool mstat[4];
int room = 1;
bool state = 1;
int curCol[3];
class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Atari - Adventure";
	}

public:
	bool OnUserCreate() override
	{
		curCol[0] = 255;
		curCol[1] = 255;
		curCol[2] = 0;
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::Pixel(100,100,100));
		mstat[0] = 1;
		mstat[1] = 1;
		mstat[2] = 1;
		mstat[3] = 1;
		switch (room) {
		case 1:
			//if (state) {
			olc::PixelGameEngine::FillRect(130, 230, 130, 10, olc::YELLOW);
			olc::PixelGameEngine::FillRect(0, 230, 100, 10, olc::YELLOW);
			olc::PixelGameEngine::FillRect(230, 0, 20, 240, olc::YELLOW);
			olc::PixelGameEngine::FillRect(0, 0, 10, 270, olc::YELLOW);
			olc::PixelGameEngine::FillRect(0, 0, 240, 10, olc::YELLOW);

			state = 0;
			//}
			if (x + (fElapsedTime * 60) > 220) {
				mstat[0] = 0;
			}
			if (x + (fElapsedTime * 60) > 120 && x + (fElapsedTime * 60) < 122 && y > 220) {
				mstat[0] = 0;
			}
			if (x - (fElapsedTime * 60) < 100 && x - (fElapsedTime * 60) > 98 && y > 220) {
				mstat[1] = 0;
			}
			if (y + (fElapsedTime * 60) > 220 && 120 < x) {
				mstat[2] = 0;
			}
			if (y + (fElapsedTime * 60) > 220 && 100 > x) {
				mstat[2] = 0;
			}

			if (x - fElapsedTime * 60 < 10) {
				mstat[1] = 0;
			}
			if (y - fElapsedTime * 60 < 10) {
				mstat[3] = 0;
			}
			if (y - fElapsedTime * 60 > 240) {
				room = 2;
				y = 10;
				curCol[0] = 0;
				curCol[1] = 100;
				curCol[2] = 100;
				//Clear(olc::Pixel(0,0,0));
			}
			break;
		case 2:
			olc::PixelGameEngine::FillRect(130, 0, 130, 10, olc::Pixel(0, 100, 100));
			olc::PixelGameEngine::FillRect(0, 0, 100, 10, olc::Pixel(0, 100, 100));
			//sides with holes right side
			olc::PixelGameEngine::FillRect(230, 0, 20, 100, olc::Pixel(0, 100, 100));
			olc::PixelGameEngine::FillRect(230, 130, 20, 130, olc::Pixel(0, 100, 100));
			//sides with holes Left Side
			olc::PixelGameEngine::FillRect(0, 0, 10, 100, olc::Pixel(0, 100, 100));
			olc::PixelGameEngine::FillRect(0, 130, 10, 130, olc::Pixel(0, 100, 100));
			//Bottom Of Area
			olc::PixelGameEngine::FillRect(0, 230, 240, 10, olc::Pixel(0, 100, 100));

			if (x + fElapsedTime * 60 > 220 && y < 100) {
				mstat[0] = 0;
			}
			if (x + fElapsedTime * 60 > 220 && y > 120) {
				mstat[0] = 0;
			}
			if (x > 220 && y - (fElapsedTime * 60) < 100) {
				mstat[3] = 0;
			}
			if (x > 220 && y + (fElapsedTime * 60) > 120) {
				mstat[2] = 0;
			}
			if (x > 230){
				room = 3;
				state = 1;
				x = 11;
				curCol[0] = 255;
				curCol[1] = 0;
				curCol[2] = 0;
			}
			if (y < 10) {
				room = 1;
				state = 1;
				y = 230;
				curCol[0] = 255;
				curCol[1] = 255;
				curCol[2] = 0;
			}
			break;
		case 3:
			//if (state) {
			olc::PixelGameEngine::FillRect(130, 230, 130, 10, olc::RED);
			olc::PixelGameEngine::FillRect(0, 230, 100, 10, olc::RED);
			olc::PixelGameEngine::FillRect(230, 0, 20, 240, olc::RED);
			olc::PixelGameEngine::FillRect(0, 0, 10, 100, olc::RED);
			olc::PixelGameEngine::FillRect(0, 130, 10, 130, olc::RED);
			olc::PixelGameEngine::FillRect(0, 0, 240, 10, olc::RED);

			state = 0;
			//}
			if (x + (fElapsedTime * 60) > 220) {
				mstat[0] = 0;
			}
			if (x + (fElapsedTime * 60) > 120 && x + (fElapsedTime * 60) < 122 && y > 220) {
				mstat[0] = 0;
			}
			if (x - (fElapsedTime * 60) < 100 && x - (fElapsedTime * 60) > 98 && y > 220) {
				mstat[1] = 0;
			}
			if (y + (fElapsedTime * 60) > 220 && 120 < x) {
				mstat[2] = 0;
			}
			if (y + (fElapsedTime * 60) > 220 && 100 > x) {
				mstat[2] = 0;
			}

			if (x - fElapsedTime * 60 < 10) {
				mstat[1] = 0;
			}
			if (y - fElapsedTime * 60 < 10) {
				mstat[3] = 0;
			}
			if (y - fElapsedTime * 60 > 240) {
				room = 2;
				y = 10;
				curCol[0] = 0;
				curCol[1] = 100;
				curCol[2] = 100;
				//Clear(olc::Pixel(0,0,0));
			}
			break;

		}
	//	olc::PixelGameEngine::FillRect(x, y, 11, 11, olc::Pixel(0, 0, 0));
		if (GetKey(olc::Key::D).bHeld && mstat[0]) { x += fElapsedTime * 60; }
		if (GetKey(olc::Key::A).bHeld && mstat[1]) { x -= fElapsedTime * 60; }
		if (GetKey(olc::Key::W).bHeld && mstat[3]) { y -= fElapsedTime * 60; }
		if (GetKey(olc::Key::S).bHeld && mstat[2]) { y += fElapsedTime * 60; }
		olc::PixelGameEngine::DrawRect(x, y, 10, 10,olc::Pixel(curCol[0], curCol[1], curCol[2]));
		return true;
	}
};

int main()
{
	Example demo;
	if (demo.Construct(240, 240, 4, 4,true))
		demo.Start();
	return 0;
}

