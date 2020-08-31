#pragma once
#include "olcPixelGameEngine.h"
#include <string>
#include <vector>
namespace pge {
	struct ren {
		olc::Decal* dcl;
		olc::Sprite* spr;
		ren(std::string path) {
			spr = new olc::Sprite(path);
			dcl = new olc::Decal(spr);
		}
		ren(olc::vf2d size, olc::PixelGameEngine * pge) {
			spr = new olc::Sprite(size.x+1,size.y+1);
			pge->SetDrawTarget(spr);
			pge->DrawRect({ 0,0 }, size);
			pge->SetDrawTarget(nullptr);
			dcl = new olc::Decal(spr);
		}
		~ren() {
			delete dcl;
			delete spr;
		}
	};
	struct aniren {
		olc::Sprite* baseSpr=nullptr;
		olc::Decal* currentDisplay=nullptr;
		olc::PixelGameEngine* pge;
		aniren(olc::PixelGameEngine* olc) {
			pge = olc;
		}
		aniren() {
		
		}
		struct frameList {
			float frameDurration;
			std::vector<olc::Sprite*> Frames;
		};
		std::map<std::string, frameList> States;
		std::string currentState;
		float timer=0;
		unsigned int currentFrame=0;
		void init(olc::Sprite *p) {
			baseSpr = new olc::Sprite(p->width, p->height);
			currentDisplay = new olc::Decal(baseSpr);
		}
		void UpdateDecal(olc::Sprite* p)
		{
			// Draw the sprite to the current frame sprite
			pge->SetDrawTarget(baseSpr);
			pge->DrawSprite(0, 0, p);
			pge->SetDrawTarget(nullptr);

			// Update Decal Texture
			currentDisplay->Update();
		}
		void  AddState(std::string StateName,std::vector<std::string> pathNames, float frameDir) {
			std::vector<olc::Sprite*> tmpS;
			for (unsigned int i = 0; i < pathNames.size(); i++) {
				tmpS.push_back(new olc::Sprite(pathNames[i]));
			}
			frameList tmp = { frameDir, tmpS};
			States[StateName] = tmp;
			currentState = StateName;
			if (this->currentDisplay == nullptr) {
				init(tmpS.front());
			}
			UpdateDecal(States[currentState].Frames[currentFrame]);
		}
		void SetState(std::string stateName) {
			currentState = stateName;
			currentFrame = 0;
			timer = 0;
		}

		void GetNextFrame(float fElapsedTime) {
			timer += fElapsedTime;
			if (timer > States[currentState].frameDurration) {
				currentFrame++;
				timer = 0;
				if (currentFrame == States[currentState].Frames.size()) {
					currentFrame = 0;
				}
				UpdateDecal(States[currentState].Frames[currentFrame]);
			}
		}
		~aniren() {
			delete currentDisplay;
			delete baseSpr;
			std::map<std::string, frameList>::iterator it = States.begin();
			while (it != States.end())
			{
				for (auto& ptr : it->second.Frames)
					delete ptr;
				it++;
			}
		}

	}; 
	struct PerformaceAniRen {
		struct FrameList {
			float FrameDurration;
			std::vector<pge::ren*> Frames;
		};
		std::map<std::string, FrameList>States;
		std::string currentState;
		float timer = 0;
		unsigned int currentFrame = 0;
		void  AddState(std::string StateName, std::vector<std::string> pathNames, float frameDir) {
			std::vector<pge::ren*> tmpS;
			for (unsigned int i = 0; i < pathNames.size(); i++) {
				tmpS.push_back(new pge::ren(pathNames[i]));
			}
			FrameList tmp = { frameDir,tmpS};
			States[StateName] = tmp;
			currentState = StateName;
		}
		void SetState(std::string stateName) {
			currentState = stateName;
			currentFrame = 0;
			timer = 0;
		}
		olc::Decal * GetNextFrame(float fElapsedTime) {
			timer += fElapsedTime;
			if (timer > States[currentState].FrameDurration) {
				currentFrame++;
				timer = 0;
				if (currentFrame == States[currentState].Frames.size()) {
					currentFrame = 0;
				}
				return States[currentState].Frames[currentFrame]->dcl;
			}
		}
		~PerformaceAniRen() {
			std::map<std::string, FrameList>::iterator it = States.begin();
			while (it != States.end())
			{
				for (auto& ptr : it->second.Frames)
					delete ptr;
				it++;
			}
		}

	};
};