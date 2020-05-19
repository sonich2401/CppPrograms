#pragma once
#include "olcPixelGameEngine.h"
#include <deque>
namespace rendev {
	struct aniSprite {
		olc::Sprite* p1 = nullptr;
		olc::Decal* p3 = nullptr;
		aniSprite() { std::cout << "INT\n"; };
		std::string state="Idle";
		std::map<std::string, std::vector<olc::Sprite*>> multiFrames;
		std::map<std::string, float> frameDurations;
		olc::PixelGameEngine* p;
		float frameTimer = 0.0f;
		unsigned int currentFrame;
		void setpoint(olc::PixelGameEngine* pge) {
			std::cout << "POIINT\n";
			p = pge;
		}
		void AddState(std::string stateName, float frameDuration, std::vector<std::string> imgPaths)
		{
			std::cout << "added STATE\n";
			for (std::string& path : imgPaths) {
				multiFrames[stateName].push_back(new olc::Sprite(path));
				std::cout << path<<"\n";
			}
			frameDurations[stateName] = frameDuration;
			p1 = multiFrames[stateName][0];
		}
		bool st=1;
		void GetMultiFrame(float fElapsedTime,olc::vf2d pos)
		{
			frameTimer += fElapsedTime;
			if (frameTimer >= frameDurations[state]) {
				currentFrame++;
				frameTimer = 0.0f;
				if (currentFrame >= multiFrames[state].size()) {
					currentFrame = 0;

				}
			}
			p1 = multiFrames[state][currentFrame];
			if (st) {
				st = 0;
				p3 = new olc::Decal(p1);
			}
			p3->sprite = p1;
			p3->Update();
			p->DrawDecal(pos, p3);

		}
		void SetState(std::string newState)
		{
			if (newState != state) {
				state = newState;
				currentFrame = 0;
			}
		}
		std::string GetState()
		{
			return state;
		}
	};
}