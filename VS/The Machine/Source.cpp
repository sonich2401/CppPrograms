#define OLC_PGE_APPLICATION
#include "Headers/olcPixelGameEngine.h"
#include "./Headers/Licence.h"
#include "Headers/Actors.h"
#include "Headers/Collision.h"
#include "rooms/Rooms.h"
#include <cstdlib>
#include <vector>
std::vector<AntiVirus> en;
Room curRoom;
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
		curRoom.loadRoom<15, 15>(room::testRoom::colDat);
		en.push_back(AntiVirus({10,10}));
		en.push_back(AntiVirus({1000,200}));
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::Pixel(0, 0, 0));
		olc::vi2d ms = {GetMouseX(),GetMouseY()};
		this->DrawRect({ 0,0 }, { 300,300 });
		for (unsigned int i = 0; i < en.size(); i++) {
			en[i].noticePlayer(ms, {5,5},fElapsedTime);
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
//ok i see you now