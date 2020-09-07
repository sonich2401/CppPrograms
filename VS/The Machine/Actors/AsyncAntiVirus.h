#pragma once
#include "../Headers/Collision.h"
#include "../Math/FloorCel.h"
struct aAntiV {
	olc::vf2d pos;
	olc::vf2d size;
	olc::vf2d rad = {150,150};
	olc::vf2d playerPos = {0,0};
	pge::ren* spr;
	float timer=0;
	float time = 0;
	bool state=0;
	void LockPlayer(olc::vf2d& playerPos,olc::vf2d &playerSize,float fElapsedTime,olc::PixelGameEngine * pge) {
		olc::vf2d colBoxPos = { pos.x - (rad.x * 2),pos.y - (rad.y * 2) };
		if (RectInRect(playerPos, playerSize, colBoxPos, rad)) {
			this->playerPos = playerPos;
			rad = {250, 250};
			timer += fElapsedTime;
			if (timer < 2.5) {
				if (timer - time > 0.25) {
					time = timer;
					state = !state;
				}
				if (state) {
					pge->DrawRect(playerPos + playerSize, this->size, olc::RED);
				}
				else {
					pge->DrawDecal(this->pos, this->spr->dcl);
				}
			}
			else {
				timer = 0;
				this->pos = this->playerPos + playerSize;
			}
		}
		else {
			this->pos = this->playerPos;
			rad = { 150,150 };
			timer = 0;
		}
	}
};