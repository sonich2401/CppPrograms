#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <iostream>
#include <fstream>
#include <string>
#include "sb.h"
//#include <bits/stdc++.h>
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