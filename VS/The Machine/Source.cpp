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
Player player;
olc::vf2d Screen = {0,0};
bool gameover = 0;
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
		player.pos = { 100,100 };
		en.push_back(AntiVirus({10,10},this));
		en.push_back(AntiVirus({200,200},this));
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::Pixel(0, 0, 0));
		int baseSpeed = 70;
		if (GetKey(olc::CTRL).bHeld) {
			//player.stam.UseStamina();
			//if (!player.stam.BelowTreshold()) {
			//	baseSpeed = 100;
			//	player.stam.refueling = 0;
			//}
			//else {
			//	player.stam.refueling = 1;
			//}
			baseSpeed = 100;
		}
		float speed = fElapsedTime * baseSpeed;
		if (GetKey(olc::W).bHeld) {
			player.pos.y -= speed;
		}
		if (GetKey(olc::S).bHeld) {
			player.pos.y += speed;
		}
		if (GetKey(olc::A).bHeld) {
			player.pos.x -= speed;
		}
		if (GetKey(olc::D).bHeld) {
			player.pos.x += speed;
		}
		
		this->FillCircle(player.pos, 10, olc::CYAN);
		olc::vi2d vSize = { 10,10 };
		for (unsigned int i = 0; i < en.size(); i++) {
			en[i].noticePlayer(player.pos, { 5,5 }, fElapsedTime);
			if (RectInRect(en[i].pos, vSize, player.pos, { 20,20 }))
				gameover = 1;
			this->FillRect(en[i].pos, {10,10}, olc::WHITE);
			en[i].pos += en[i].vel;
		}
		if (gameover) {
			Clear(olc::Pixel(0, 0, 0));
			this->DrawStringDecal({ 200,300 }, "Game Over", olc::WHITE,{5,5});
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