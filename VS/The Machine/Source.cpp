#define OLC_PGE_APPLICATION
#include "Headers/olcPixelGameEngine.h"
#include "./Headers/Licence.h"
#include "Headers/Actors.h"
#include "Headers/Collision.h"
#include "rooms/Rooms.h"
#include "Headers/Sprite.h"
#include "Headers/RoomLoading.h"
#include <cstdlib>
#include <vector>
std::vector<AntiVirus> en;
Player player;
olc::vf2d Screen = {0,0};
Room curRoom;
pge::ren* antiV;
bool gameover = 0;
class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Evil Computer";
	}

public:
	bool OnUserCreate() override
	{
		player.pos = { 300,404 };
		player.size = {20,20};
		curRoom.LoadRoom(room::testRoom::colDat,this);
		player.spr = new pge::ren("./pic/Player.png");
		antiV = new pge::ren("./pic/aniV.png");
		en.push_back(AntiVirus({30,30},this));
		en.push_back(AntiVirus({250,500},this));
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		int baseSpeed = 70;
		this->DrawStringDecal({ 0,0 }, Screen.str());
		this->DrawStringDecal({ 0,10 }, player.pos.str());
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
		if (GetKey(olc::ESCAPE).bPressed) {
			gameover = 0;
			player.pos = { 200,200 };
		}
		this->DrawDecal(player.pos, player.spr->dcl);
		olc::vi2d vSize = { 10,10 };
		curRoom.CheckCollsion(&player.pos, &spd, player.size,Screen,1, this);
		for (unsigned int i = 0; i < en.size(); i++) {
			en[i].noticePlayer(player.pos, player.size, fElapsedTime);
			if (RectInRect(en[i].pos-Screen, vSize, player.pos, player.size))
				gameover = 1;
			this->DrawDecal(en[i].pos-Screen, antiV->dcl);
			curRoom.CheckCollsion(&en[i].pos, &en[i].vel, vSize, Screen,0,this);
			en[i].pos += en[i].vel;
		}
		for (unsigned int i = 0; i < curRoom.colDat.size(); i++) {
			this->DrawDecal({ (float)curRoom.colDat[i].x-Screen.x,(float)curRoom.colDat[i].y-Screen.y }, curRoom.gfxDat[i]->dcl);
		}
		//player.pos += spd;
		Screen += spd;
		if (gameover) {
			//Clear(olc::Pixel(0, 0, 0));
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