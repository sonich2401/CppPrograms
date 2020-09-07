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
Player player;
olc::vf2d Screen = {0,0};
Room curRoom;
pge::ren* antiV;
std::vector<AntiVirus> en1;
bool gameover = 0;
unsigned int gamestate = 0;
float hitstun=0;
void Room1(olc::PixelGameEngine * pge) {
	curRoom.LoadRoom(room::testRoom::colDat, pge);
	en1.clear();
	en1.push_back(AntiVirus({ 600, 30 }, pge));
	en1.push_back(AntiVirus({ 250,425 }, pge));
}
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
		player.pos = { 300 - 20,300 - 20 };
		player.size = { 20,20 };
		Room1(this);
		player.spr = new pge::ren("./pic/Player.png");
		antiV = new pge::ren("./pic/aniV.png");
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		int baseSpeed = 70;
		float speed = fElapsedTime * baseSpeed;
		olc::vi2d vSize = { 10,10 };
		olc::vf2d spd = { 0,0 };
		switch (gamestate) {
		case 0:
			this->DrawStringDecal({ 30,183 + 50 }, "Welcome To Death", olc::WHITE, { 4,4 });
			this->DrawStringDecal({ 20,183 + 100 }, "Press Enter to Die", olc::WHITE, { 4,4 });
			if (GetKey(olc::ENTER).bPressed) {
				gamestate = 1;
			}
			break;
		case 1:
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
			speed = fElapsedTime * baseSpeed;
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
			}
			//player drawing
			this->DrawDecal(player.pos - Screen, player.spr->dcl);
			curRoom.CheckCollsion(&player.pos, &spd, player.size, this);
			//AntiVirus Pyhsics
			for (unsigned int i = 0; i < en1.size(); i++) {
				en1[i].noticePlayer(player.pos, player.size, Screen, fElapsedTime);
				if (RectInRect(en1[i].pos, vSize, player.pos, player.size))
					gamestate = 1000;
				this->DrawDecal(en1[i].pos - Screen, antiV->dcl);
				curRoom.CheckCollsion(&en1[i].pos, &en1[i].vel, vSize, this);
				en1[i].pos += en1[i].vel * fElapsedTime * 60;
			}
			//Level Geometry
			for (unsigned int i = 0; i < curRoom.colDat.size(); i++) {
				this->DrawDecal({ (float)curRoom.colDat[i].x - Screen.x,(float)curRoom.colDat[i].y - Screen.y }, curRoom.gfxDat[i]->dcl);
			}
			Screen += spd;
			player.pos += spd;
			break;
		case 1000:
			return false;
			break;
		}
		return true;
	}
};
int main()
{
	Example demo;
	//system("title Program");
	//std::cout << "You are a young man going to colledge. Your family lives hundreds of miles away and you don't have manny friends";
	//Sleep(2000);
	//system("cls");
	//std::cout << "The only friend that you have is your college roomate Peter.";
	//Sleep(2000);
	//system("cls");
	//std::cout << "A friend meaning he ignores you and doesn't try to make fun of you.";
	//Sleep(2000);
	//system("cls");
	//std::cout << "The truth is your life has not been very sucessful, you dont really matter to anyone but your family";
	//Sleep(2000);
	//system("cls");
	//std::cout << "But that is why you are at college! You have come to better yourslef! You will finnaly become a somebody!";
	//Sleep(2000);
	//system("cls");
	//std::cout << "Someone knocks on your door...";
	//Sleep(2000);
	//system("cls");
	//std::cout << "You slowly open the door just a crack to see who it is";
	//Sleep(2000);
	//system("cls");
	//std::cout << "You See a man in a suit who explains that your grandfather has died and your parents want you to take care of cleaning up his house becuase you are the closest to your house";
	//Sleep(2000);
	if (demo.Construct(600, 600, 1, 1,false,false))
		demo.Start();
	system("cls");
	std::cout << "\nYou Wake Up in a Hosipital, completely disoriented. You see someone reach down and unplug your life support.";
	if (gamestate == 1000) {
		std::cout << "\nYour eyes get heavy and you close your eyes.\n";
	}
	else {
		std::cout << "\nYou reach your hand out and grab the person's arm. If you hadn't woke up sooner you may have died!\n";
	}
	std::cout << "Game Over\n";
	system("pause");
	return 0;
}