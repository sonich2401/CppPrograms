#pragma once
#include "../Headers/olcPixelGameEngine.h"
#include "../Math/Rotate.h"
#include "../Headers/Collision.h"
char getSign(float num) {
	return (-1 * (num < 0)) + (num >= 0);
}

struct AntiVirus {
	AntiVirus() {
	}
	AntiVirus(olc::vf2d _pos,olc::PixelGameEngine * olc) {
		pos = _pos;
		home = _pos;
		pge = olc;
	}
	olc::PixelGameEngine* pge;
	olc::vf2d pos;
	olc::vf2d vel;
	olc::vf2d home;
	float timer = 0;
	void gotoPoint(olc::vi2d point, float speed) {
		const float baseSpeed = 100;
		olc::vf2d slope = point - olc::vi2d(pos);
		vel.x = getSign(slope.x) * speed * !(point.x + speed > pos.x && point.x - speed < pos.x);
		vel.y = getSign(slope.y) * speed * !(point.y + speed > pos.y && point.y - speed < pos.y);
	}
	void noticePlayer(olc::vf2d pos,olc::vf2d PlayerSize,float fElapsedTime) {
		float rad = 150;
		olc::vf2d colBoxSize = {rad*2,rad*2};
		olc::vf2d colBoxPos = { home.x - (colBoxSize.x / 2),home.y - (colBoxSize.y / 2) };
		if (RectInRect(pos, PlayerSize, colBoxPos,colBoxSize )) {
			timer += fElapsedTime;
		}
		else { 
			if (timer > 0) {
				timer -= fElapsedTime;
			}
		}
		if (timer > 3) {
			gotoPoint(pos, 1);
		}
		else {
			vel = { 0,0 };

			if (GetDistance(home,this->pos)>1) {
				gotoPoint(home, 0.5);
			}
		}
	}

};