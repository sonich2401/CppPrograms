
#define OLC_PGE_APPLICATION
#define OLC_PGEX_GRAPHICS2D
#define OLC_PGEX_ANIMSPR

#include "olcPixelGameEngine.h"
#include "test.h"
#include "utilFunc.h"
#include "levels.h"
bool st=0;
bool st2 = 0;
uint8_t dirstate=0;
uint8_t odir = 1;
uint8_t tmpdir=0;
float orgpos=0;
olc::vf2d newpos;
const int speed=40;

class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Frogger";
	}

public:
	rendev::aniSprite sprite;
	rendev::aniSprite water;
	olc::Sprite* froggyimg[4];
	olc::Decal* foggy[5];
	std::string stat_L[5];
	olc::vf2d pos = { 0.0f,0.0f };
	std::string staticFile[4];
	float distance=0;
	int orgdistance = 0;
	const void chdir(int newdir) { //function made for the purpose of code resuablitly. This function sets the direction of the frog and where the disired position should be
		st = 1;
		sprite.SetState(stat_L[newdir]);
		if (st2) {
			tmpdir = newdir;
		}
		else {
			dirstate = newdir;
		}
		switch (newdir) {
		case 1:
			newpos.y = pos.y - 10;
			break;
		case 2:
			newpos.y = pos.y + 10;
			break;
		case 3:
			newpos.x = pos.x - 10;
			break;
		case 4:
			newpos.x = pos.x + 10;
			break;
		}
	}
	bool OnUserCreate() override
	{
		newpos = { 0.0f,0.0f };
		//static frog sprite
		froggyimg[1] =   new olc::Sprite("C://Users/mener/OneDrive/Desktop/Image1.png");
		froggyimg[0] =   new olc::Sprite("C://Users/mener/OneDrive/Desktop/Image1_2.png");
		froggyimg[2] = new olc::Sprite("C://Users/mener/OneDrive/Desktop/Image1_3.png");
		froggyimg[3] = new olc::Sprite("C://Users/mener/OneDrive/Desktop/Image1_1.png");
		forrange(0,4) {foggy[i+1] = new olc::Decal(froggyimg[i]);}
		//add in animations
		//       frog
		sprite.setpoint(this);
		sprite.AddState("forwards", 0.1f, {
		"C://Users/mener/OneDrive/Desktop/Image1.png",
		"C://Users/mener/OneDrive/Desktop/Image2.png",
		"C://Users/mener/OneDrive/Desktop/Image1.png",
		"C://Users/mener/OneDrive/Desktop/Image2.png" });
		sprite.AddState("down", 0.1f, {
"C://Users/mener/OneDrive/Desktop/Image1_2.png",
"C://Users/mener/OneDrive/Desktop/Image2_2.png",
"C://Users/mener/OneDrive/Desktop/Image1_2.png",
"C://Users/mener/OneDrive/Desktop/Image2_2.png" });
		sprite.AddState("left", 0.1f, {
"C://Users/mener/OneDrive/Desktop/Image1_3.png",
"C://Users/mener/OneDrive/Desktop/Image2_3.png",
"C://Users/mener/OneDrive/Desktop/Image1_3.png",
"C://Users/mener/OneDrive/Desktop/Image2_3.png" });
		sprite.AddState("right", 0.1f, {
"C://Users/mener/OneDrive/Desktop/Image1_1.png",
"C://Users/mener/OneDrive/Desktop/Image2_1.png",
"C://Users/mener/OneDrive/Desktop/Image1_1.png",
"C://Users/mener/OneDrive/Desktop/Image2_1.png" });
		sprite.SetState("forwards");
		//        water
			water.setpoint(this);
			water.AddState("still", 0.5f, {
"C://Users/mener/OneDrive/Desktop/water1.png",
"C://Users/mener/OneDrive/Desktop/water2.png",
"C://Users/mener/OneDrive/Desktop/water1.png",
"C://Users/mener/OneDrive/Desktop/water2.png" });
			water.SetState("still");
			//this is used in the chdir() function as a list of vaild animations
			stat_L[2] = "forwards";
			stat_L[1] = "down";
			stat_L[3] = "left";
			stat_L[4] = "right";
		return true;
	}
	bool OnUserUpdate(float fElapsedTime) override
	{
		if (dirstate == 0) { //check if process is done
			st2 = 0;
		}
		else { st2 = 1; }
		if (GetKey(olc::W).bPressed) { //up
			chdir(2);
		}
		if (GetKey(olc::S).bPressed) { //down
			chdir(1);
		}
		if (GetKey(olc::A).bPressed) { //left
			chdir(3);
		}
		if (GetKey(olc::D).bPressed) { //right
			chdir(4);
		}
		/*if a movement process is complete and a different key was pressed earlier, 
		the current direction will be overiten by the stored diffent dircetoin.

		*/
		if (((tmpdir != 0) && odir != 0)&&dirstate==0) { 

			st = 1;
			dirstate = tmpdir;
			tmpdir = 0;
		}
		//st is a bool used to check if a key action has occured or is in progress
if (st) {
	switch (dirstate) {
		//up
	case uint8_t(1):
		odir = 1;
		if (pos.y - fElapsedTime*speed > newpos.y) {
			pos.y -= fElapsedTime*speed;
		}
		else { st = 0; dirstate = 0; pos.y -= fElapsedTime * speed;}
		break;
		//down
	case uint8_t(2):
		odir = 2;
		if (pos.y + fElapsedTime*speed < newpos.y) {
			pos.y += fElapsedTime*speed;
		}
		else { st = 0; dirstate = 0; pos.y += fElapsedTime*speed;}
		break;
		//left
	case uint8_t(3):
		odir = 3;
		if (pos.x - fElapsedTime*speed > newpos.x) {
			pos.x -= fElapsedTime*speed;
		}
		else { st = 0; dirstate = 0; pos.x -= fElapsedTime*speed;}
		break;
		//right
	case uint8_t(4):
		odir = 4;
		if (pos.x + fElapsedTime*speed < newpos.x) {
			pos.x += fElapsedTime*speed;
		}
		else { st = 0; dirstate = 0; pos.x += fElapsedTime*speed;}
		break;
	}
	//draw animated frog 
	sprite.GetMultiFrame(fElapsedTime, {pos.x,120.0});
}
else {
	//draw static image if nothing needs to be animated
	olc::PixelGameEngine::DrawDecal({ pos.x ,120.0}, foggy[odir]);
}
//draw enviroment
		water.GetMultiFrame(fElapsedTime, {float(0),pos.y});
		return true;
	}
};

int main()
{
	Example demo;
	if (demo.Construct(260, 240, 4, 4))
		demo.Start();
	return 0;
}
