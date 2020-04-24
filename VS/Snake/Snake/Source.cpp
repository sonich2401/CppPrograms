#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <cmath>
#include <deque> 
int gamespace[18][10];
int gamestate;
float timer,timer2;
float al;
int start[2];
float x;
bool dirt;
short int random[2];
float deltaco;
float speed;
short int direction[3];
int lastfill[2];
std::deque <int> snakex;
std::deque <int> snakey;
class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Snake";
	}
public:
	bool OnUserCreate() override
	{
		srand(time(NULL));
		al = 0.9;
		gamestate = 0;
		x = 1;
		SetPixelMode(olc::Pixel::ALPHA);
		dirt = false;
		speed = 1;
		gamespace[5][5]=1;
		gamespace[3][3] = 2;
		return true;
	}
	bool OnUserUpdate(float fElapsedTime) override
	{
		switch (gamestate) {
		case 0:
			Clear(olc::Pixel(0, 0, 0));
			timer = timer+(100 * fElapsedTime);
			if (timer < 400){
				olc::PixelGameEngine::DrawString(60, 175, "RenDev Games Presents...", olc::Pixel(255,255,255),2);
			}
			else { olc::PixelGameEngine::DrawString(60, 175, "RenDev Games Presents...", olc::Pixel(255, 255, 255), 2);
				al = al + 0.5;
				if (al < 255) {
					olc::PixelGameEngine::DrawString(100, 225, "Using the 'PGE'", olc::Pixel(255, 255, 255, al), 2);
					olc::PixelGameEngine::DrawString(10, 255, "By: Javid9x  (onelonecoder.com)", olc::Pixel(255, 255, 255, al), 2);
				}
				else {
					olc::PixelGameEngine::DrawString(100, 225, "Using the 'PGE'", olc::Pixel(255, 255, 255,255), 2);
					olc::PixelGameEngine::DrawString(10, 255, "By: Javid9x  (onelonecoder.com)", olc::Pixel(255, 255, 255,255), 2);
				}
			if (timer > 1000) { gamestate = 1; timer = 0; } }
			break;
		case 1:
			Clear(olc::Pixel(0, 0, 0));
			olc::PixelGameEngine::DrawString((ScreenWidth() / 2)-125, (ScreenHeight() / 2)-50, "S N A K E",olc::Pixel(0,255,0),3);
			timer = timer + (100 * fElapsedTime);
			if (timer > 200) {
				olc::PixelGameEngine::DrawString((ScreenWidth() / 2) - 80, (ScreenHeight() / 2), "Decaf Edition", olc::Pixel(0, 255, 0), 1);
				if (timer > 400) {
					//TODO: Add Difficulty Options
					olc::PixelGameEngine::DrawString(80, 400, "Press Enter To Begin", olc::Pixel(100, 255, 100), 2); olc::PixelGameEngine::DrawString(175, 450, "Exit Game");
					if (olc::PixelGameEngine::GetMouse(0).bHeld) {
						if (GetMouseX() > 150 && GetMouseX() < 300 && GetMouseY() > 450) { return 0; }
					}
					}
			}
			if (GetKey(olc::Key::ENTER).bHeld) { gamestate = 2; timer = 0; al = 0.7; Clear(olc::Pixel(0, 0, 255));
			}
			
			break;
		case 2:
			if (!dirt) {
				for (int i = 0; i < 18; i++) {
					for (int j = 0; j < 10; j++) {
						olc::PixelGameEngine::DrawRect(i * (ScreenWidth() / 18), (j * (ScreenWidth() / 18)) + 100, ScreenWidth() / 18, ScreenWidth() / 18);
						if (gamespace[i][j] == 1) {
							olc::PixelGameEngine::FillRect(i * (ScreenWidth() / 18), (j * (ScreenWidth() / 18)) + 100, ScreenWidth() / 18, ScreenWidth() / 18,olc::Pixel(0,255,0));
						}
						if (gamespace[i][j] == 2) {
						olc::PixelGameEngine::FillRect(i * (ScreenWidth() / 18), (j * (ScreenWidth() / 18)) + 100, ScreenWidth() / 18, ScreenWidth() / 18,olc::Pixel(255,0,0));
						}

					}
				}
				dirt = true;
				gamespace[5][5] = 0;
			}
			olc::PixelGameEngine::FillRect(0, 400, ScreenWidth(), 100, olc::Pixel(0,0,0));
			SetPixelMode(olc::Pixel::ALPHA);
			if (dirt) {
				timer = timer + (fElapsedTime);
				timer2 = timer2 + (2 * fElapsedTime);
				x = timer * 100;
				if (x-400 > ScreenWidth() + 20) { timer = -75; }
				olc::PixelGameEngine::DrawString(x, 450, "GET READY!", olc::Pixel(100, 255, 100), 2);
				olc::PixelGameEngine::DrawString(x-200, 450, "GET READY!", olc::Pixel(100, 255, 100), 2);
				olc::PixelGameEngine::DrawString(x-400, 450, "GET READY!", olc::Pixel(100, 255, 100), 2);
				if (timer2 > 25) {
					gamestate = 3; timer = 0; timer2 = 0; x = 0; snakex.push_front(5); snakey.push_front(5);
				}
			}

			break;
		case 3:
			if (dirt) {
				for (int i = 0; i < 18; i++) {
					for (int j = 0; j < 10; j++) {
						olc::PixelGameEngine::DrawRect(i * (ScreenWidth() / 18), (j * (ScreenWidth() / 18)) + 100, ScreenWidth() / 18, ScreenWidth() / 18);
					}
				}
				dirt = false;
			}
			timer = timer + (1 * fElapsedTime);
			if (GetKey(olc::Key::UP).bHeld && !GetKey(olc::Key::DOWN).bHeld && !GetKey(olc::Key::LEFT).bHeld && !GetKey(olc::Key::RIGHT).bHeld) { direction[0] = 1; }
			if (GetKey(olc::Key::DOWN).bHeld && !GetKey(olc::Key::UP).bHeld && !GetKey(olc::Key::LEFT).bHeld && !GetKey(olc::Key::RIGHT).bHeld) { direction[0] = 2; }
			if (GetKey(olc::Key::LEFT).bHeld && !GetKey(olc::Key::DOWN).bHeld && !GetKey(olc::Key::UP).bHeld && !GetKey(olc::Key::RIGHT).bHeld) { direction[0] = 3; }
			if (GetKey(olc::Key::RIGHT).bHeld && !GetKey(olc::Key::DOWN).bHeld && !GetKey(olc::Key::LEFT).bHeld && !GetKey(olc::Key::UP).bHeld) { direction[0] = 4; }
			if (GetKey(olc::Key::ENTER).bHeld) { return 0; }
			switch (direction[0]) {
			case 1:
				direction[2] = -1;
				direction[1] = 0;
				break;
			case 2:
				direction[2] = 1;
				direction[1] = 0;
				break;
			case 3:
				direction[1] = -1;
				direction[2] = 0;
				break;
			case 4:
				direction[1] = 1;
				direction[2] = 0;
				break;
			}
			if (timer > speed) {
				snakex.push_front(snakex.front() + direction[1]);
				snakey.push_front(snakey.front() + direction[2]);
				if (snakex.front() >= 0 && snakey.front()>=0 && snakey.front()<=9 && snakex.front()<=17) {
					switch (gamespace[snakex.front()][snakey.front()]) {
					case 0:
						gamespace[snakex.front()][snakey.front()] = 1;
						lastfill[1] = snakey.back();
						snakey.pop_back();
						lastfill[0] = snakex.back();
						gamespace[lastfill[0]][lastfill[1]] = 0;
						snakex.pop_back();
						olc::PixelGameEngine::FillRect(lastfill[0] * (ScreenWidth() / 18), (lastfill[1] * (ScreenWidth() / 18)) + 100, ScreenWidth() / 18, ScreenWidth() / 18, olc::Pixel(0, 0, 0));
						olc::PixelGameEngine::DrawRect(lastfill[0] * (ScreenWidth() / 18), (lastfill[1] * (ScreenWidth() / 18)) + 100, ScreenWidth() / 18, ScreenWidth() / 18);
						olc::PixelGameEngine::FillRect(snakex.front() * (ScreenWidth() / 18), (snakey.front() * (ScreenWidth() / 18)) + 100, ScreenWidth() / 18, ScreenWidth() / 18, olc::Pixel(0, 255, 0));
						break;
					case 1:
						gamestate = 4;
						timer = 0;
						Clear(olc::Pixel(0, 0, 0));
						olc::PixelGameEngine::DrawString(0, 0, "<GAME OVER>", olc::Pixel(255, 255, 255), 2);
						olc::PixelGameEngine::DrawString(0, 100, "Hold Enter To Quit Game!", olc::Pixel(255, 255, 255), 2);
						break;
					case 2:
						dirt = true;
						while (dirt) {
							random[0] = rand() % 17;
							random[1] = rand() % 10;
							if (gamespace[random[0]][random[1]] == 0) { dirt = false; }
						}
							gamespace[random[0]][random[1]] = 2;
							gamespace[snakex.front()][snakey.front()] = 1;
						speed = speed - 0.05;
						olc::PixelGameEngine::FillRect(random[0] * (ScreenWidth() / 18), (random[1] * (ScreenWidth() / 18)) + 100, ScreenWidth() / 18, ScreenWidth() / 18, olc::Pixel(255, 0, 0));
						olc::PixelGameEngine::FillRect(snakex.front() * (ScreenWidth() / 18), (snakey.front() * (ScreenWidth() / 18)) + 100, ScreenWidth() / 18, ScreenWidth() / 18, olc::Pixel(0, 255, 0));
						break;
					default:
						gamestate = 4;
					}
				}
				else {
					gamestate = 4;
					timer = 0;
					olc::PixelGameEngine::DrawString(0, 0, "<GAME OVER>", olc::Pixel(255, 255, 255), 2);
					olc::PixelGameEngine::DrawString(0, 100, "Hold Enter To Quit Game!", olc::Pixel(255, 255, 255), 2);
					Clear(olc::Pixel(0, 0, 0));
				}
				timer = 0;
			}
			break;
		case 4:
			olc::PixelGameEngine::DrawString(0, 200, "GAME OVER", olc::Pixel(255, 0, 0), 4);
			olc::PixelGameEngine::DrawString(0,400,"Press Enter to Continue",olc::Pixel(255,0,0),2);
			if (GetKey(olc::Key::ENTER).bHeld) { gamestate=-1; }
			break;
		case -1:
			for (int i = 0; i < 18; i++) {
				for (int j = 0; j < 10; j++) {
					gamespace[i][j] = 0;
				}
			}
			al = 0.9;
			gamestate = 0;
			x = 1;
			SetPixelMode(olc::Pixel::ALPHA);
			dirt = false;
			speed = 1;
			gamespace[5][5] = 1;
			gamespace[3][3] = 2;
			snakex.clear();
			snakey.clear();
			snakex.push_front(5);
			snakey.push_front(5);
			timer = 0;
			break;
		default:
			std::cout << "ERROR: UNDEFINED GAMEMODE\n";
		}
		return true;
	}
};
int main()
{
	Example demo;
	if (demo.Construct(500, 500, 1, 1,true))
		demo.Start();
	return 0;
}