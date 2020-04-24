#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "";
	}

public:
	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
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
