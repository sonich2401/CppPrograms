#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <iostream>
int a = 0;
int b = 0;
int Idata[16][16];

	// Override base class with your custom functionality
	class Example : public olc::PixelGameEngine
	{
	public:
		Example()
		{
			sAppName = "Example";
		}
	public:
		bool OnUserCreate() override
		{
			// Called once at the start, so create things here
			a = 0;
			b=0;
			Idata[8][8] = 1;
			Idata[9][9] = 1;
			Idata[10][9] = 1;
			Idata[8][5] = 1;
			Idata[10][5] = 1;
			for (int y = 0; y < 16; y++) { Idata[0][y] = 1; }
			for (int y = 0; y < 16; y++) { Idata[y][0] = 1; }
			for (int y = 0; y < 16; y++) { Idata[15][y] = 1; }
			for (int y = 0; y < 16; y++) { Idata[y][15] = 1; }
			return true;
		}
		bool OnUserUpdate(float fElapsedTime) override
		{
			Sleep(1000 / 70);
			Clear(olc::Pixel(0,0,0));
			// called once per frame, draws random coloured pixels
			if (GetKey(olc::Key::DOWN).bHeld)
			{
				b++;
			}
			if (GetKey(olc::Key::UP).bHeld)
			{
				b--;
			}
			if (GetKey(olc::Key::RIGHT).bHeld)
			{
				a++;
			}
			if (GetKey(olc::Key::LEFT).bHeld)
			{
				a--;
			}
			for (int x = 0; x < 16; x++)
				for (int y = 0; y < 16; y++)
					if (Idata[x][y] == 1) {
						if ((b + 16) + y > ScreenHeight()) { b--; }
						Draw(x+a, y+b, olc::Pixel(255,255,255));
					}
			return true;
			
		}
	};
	int main()
	{
		Example demo;
		if (demo.Construct(256, 240, 4, 4))
			demo.Start();
		return 0;
	}
