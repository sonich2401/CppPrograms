#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <deque>
#include <cstdlib> 
std::deque <int> L_Bike[2][2];
int gamestate;
float timer[5];
bool state[2];
int gamespace[100][100];
int al[2];
int rng[2][2];
int titleDir[2][3];
float titlepos[2][2];
float titleposC(bool xy, float pos, int rng, float eTime, float sp) {
	float newpos=pos;
	switch (rng) {
	case 1:
			newpos += (eTime * sp);
			break;
	case 2:
			newpos -= (eTime * sp);
		break;
	case 3:
			newpos += (eTime * sp);
		break;
	case 4:
			newpos -= (eTime * sp);
		break;
	default:
		std::cout << "ERROR:: INVALID RANDOM DIRECTION AT TITLE SCREEN\n";
	}
	if (xy) {
		if (rng == 1 || rng == 2) { return newpos; }
		else { return pos; }
	}
	else {
		if (rng == 3 || rng == 4) { return newpos; }
		else { return pos; }
	}
	std::cout << "lastRand: " << rng<< "\n\t";
}
// Override base class with your custom functionality
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
		system("title Tron - Using the 'Pixel Game Engine' By: javid9x  onelonecoder.com");
		gamestate = -1;
		return true;
	}
	bool OnUserUpdate(float fElapsedTime) override
	{
		SetPixelMode(olc::Pixel::ALPHA);
		switch (gamestate) {
		case -1:
			//TODO Initalize varibles
			//timer[0] = timer[0] + (2 * fElapsedTime);
			timer[1] = 5;
			timer[3] = 5;
			gamestate = 0;
			break;
		case 0:
			//TODO RenDev Games Intro
			int mult;
			Clear(olc::Pixel(0, 0, 0));
			timer[0]=timer[0]+fElapsedTime;
			timer[2] = timer[2] + fElapsedTime;
			if (timer[0] < 1) {
				timer[0] = 0;
				if (timer[2] < 7) { mult = -1; }
				else { mult = 1; }
				timer[1]=timer[1]+(0.03*mult);
				if (timer[1] < 1) { timer[1] = 1; }
				al[0] = 255 / timer[1];
				if (timer[2] > 2) { 
					timer[3] = timer[3] + (0.03 * mult);
					if (timer[3] < 1) { timer[3] = 1; }
					al[1] = 255 / timer[3];
					olc::PixelGameEngine::DrawString(10,100,"Running on the 'PGE'",olc::Pixel(255,255,255,al[1]),2);
					olc::PixelGameEngine::DrawString(10, 130, "Made By: Javid9x ( onelonecoder.com )", olc::Pixel(255, 255, 255, al[1]), 2);
				}
				olc::PixelGameEngine::DrawString(0, 0, "RenDev Games Presents...", olc::Pixel(255, 255, 255, al[0]), 3);
				if (timer[2] > 9) { gamestate = 1; Clear(olc::Pixel(0, 0, 0));}
			}

			break;
		case 1:
			if (!state[0]) {
			if (timer[2] > 9) {
				titlepos[0][1] = 100; titlepos[0][0] = 100;
				timer[1] = 0; timer[0] = 0; timer[3] = 0; al[0] = 0; al[1] = 0; mult = 0; state[0] = true; timer[2] = 0; rng[0][1] = 1; rng[0][0] = 1;
					olc::Sprite p = olc::Sprite::Sprite("C://Users/mener/OneDrive/Documents/GitHub/CppPrograms/VS/Nort/Tron/t.png");
					olc::PixelGameEngine::DrawSprite(100, 100, &p, 1);
				}
			}
			timer[0]+=fElapsedTime;
			if (timer[0] > ((rand()% 8)+2.0)) {
				timer[0] = 0;
				rng[0][0] = rng[0][1];
				rng[0][1] = (rand() % 4) + 1.0;
					while (rng[0][0] == rng[0][1] && abs(rng[0][1]-rng[0][0])!=1) {
						rng[0][1] = (rand() % 4) + 1.0;
						if (rng[0][0] == 1 && rng[0][1] == 2) {
							rng[0][1] = 3;
						}
						if (rng[0][0] == 2 && rng[0][1] == 1) {
							rng[0][1] = 4;
						}
						if (rng[0][0] == 3 && rng[0][1] == 4) {
							rng[0][1] = 1;
						}
						if (rng[0][0] == 4 && rng[0][1] == 3) {
							rng[0][1] = 2;
						}

					}
				std::cout << rng[0][1] << "\n";
				
			}
			titlepos[0][0]= titleposC(0,titlepos[0][0],rng[0][1],fElapsedTime,15);
			titlepos[0][1] = titleposC(1,titlepos[0][1], rng[0][1], fElapsedTime, 15);
			olc::PixelGameEngine::Draw(titlepos[0][0], titlepos[0][1], olc::Pixel(100,100,255));
			//std::cout << titlepos[0][0] << " X: "<<titlepos[0][1]<<"\n";
			
			//TODO TitleScreen
			//return 0;
			break;
		case 2:
			//TODO Handicap Screen
			break;
		case 3:
			//TODO Get Ready Screen
			break;
		case 4:
			//TODO GameSpace
			break;
		case 5:
			//TODO Gameover
			break;
		case 6:
			//TODO Result Screen
			break;
		}

				if (GetKey(olc::Key::ENTER).bHeld) {
					return false;
				}
		return true;
		
	}
};
int main()
{
	Example demo;
	if (demo.Construct(725,500,1,1))
		demo.Start();
	return 0;
}