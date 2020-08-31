#pragma once
#include "Collision.h"
#include "Actors.h"
#include "Sprite.h"
struct Room {
	std::vector<ColBox> colDat;
	std::vector<pge::ren*> gfxDat = {nullptr};
	void LoadRoom(const std::vector<ColBox> input,olc::PixelGameEngine * pge) {
		colDat = input;
		for (auto ptr : gfxDat)
			if (ptr != nullptr)
				delete ptr;
			else
				gfxDat.pop_back();
		
		for (auto rect : colDat) {
			gfxDat.push_back(new pge::ren({ (float)rect.w,(float)rect.h }, pge));
			
		}
		
	}
	void CheckCollsion(olc::vf2d* Pos, olc::vf2d* vel, olc::vf2d size, olc::PixelGameEngine* pge) {
		
		for (auto rect : colDat) {
			//olc::vf2d thisRect[2] = { {(float)rect.x - offset.x,(float)rect.y-offset.y}, {(float)rect.w,(float)rect.h} };
			rect.Collision(Pos, vel, size,pge);
			//pge->FillRect({ rect.x,rect.y }, { rect.w,rect.h }, olc::YELLOW);
		}

	}
};