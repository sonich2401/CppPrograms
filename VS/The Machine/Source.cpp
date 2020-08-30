#define OLC_PGE_APPLICATION
#include "Headers/olcPixelGameEngine.h"
#include "./Headers/Licence.h"
#include "Headers/Actors.h"
#include "Headers/Collision.h"
#include "rooms/Rooms.h"
#include <cstdlib>
#include <vector>
std::vector<AntiVirus> en;
Player player;
olc::vf2d Screen = {0,0};
ColBox curRoom = { 100,100,100,100 };
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
		player.pos = { 300,400 };
		player.size = {10,10};
		en.push_back(AntiVirus({10,10},this));
		en.push_back(AntiVirus({250,200},this));
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
		olc::vf2d spd = {0,0};
		if (GetKey(olc::W).bHeld) {
			spd.y -= speed;
		}
		if (GetKey(olc::S).bHeld) {
			spd.y += speed;
		}
		if (GetKey(olc::A).bHeld) {
			spd.x -= speed;
		}
		if (GetKey(olc::D).bHeld) {
			spd.x += speed;
		}
		this->FillRect(player.pos, player.size, olc::CYAN);
		olc::vi2d vSize = { 10,10 };
		curRoom.Collision(&player.pos, &spd, player.size, this);
		this->FillRect({ curRoom.x,curRoom.y }, { curRoom.w,curRoom.h },olc::YELLOW);
		for (unsigned int i = 0; i < en.size(); i++) {
			en[i].noticePlayer(player.pos, player.size, fElapsedTime);
			if (RectInRect(en[i].pos, vSize, player.pos, player.size))
				gameover = 1;
			this->FillRect(en[i].pos, {10,10}, olc::WHITE);
			en[i].pos += en[i].vel;
		}
		player.pos += spd;
		this->DrawStringDecal({0,0},player.pos.str());
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