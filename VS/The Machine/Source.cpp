#define OLC_PGE_APPLICATION
#include "Headers/olcPixelGameEngine.h"
#include "./Headers/Licence.h"
#include "Headers/Actors.h"
#include "Headers/Collision.h"
#include <cstdlib>
#include <vector>
std::vector<AntiVirus> en;
class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Tron";
	}

public:
	bool OnUserCreate() override
	{
		en.push_back(AntiVirus() = { {1000,10},{0,0} });
		en.push_back(AntiVirus() = { {10,10},{0,0} });
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::Pixel(0, 0, 0));
		olc::vi2d ms = {GetMouseX(),GetMouseY()};
		for (unsigned int i = 0; i < en.size(); i++) {
			en[i].gotoPoint(ms, 2);
			this->FillRect(en[i].pos, {10,10}, olc::WHITE);
			en[i].pos += en[i].vel;
		}
		return true;
	}
};
int main()
{
	Example demo;
	if (demo.Construct(600, 600, 1, 1,false,true))
		demo.Start();
	
	return 0;
}
