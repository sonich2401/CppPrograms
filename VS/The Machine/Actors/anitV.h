#pragma once
#include "../Headers/olcPixelGameEngine.h"
#include "../Math/Rotate.h"
char getSign(float num) {
	return (-1 * (num < 0)) + (num >= 0);
}
bool IsPointInRect(olc::vi2d point, olc::vf2d pos,olc::vf2d size) {
	return 0;
}
struct AntiVirus {
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
};