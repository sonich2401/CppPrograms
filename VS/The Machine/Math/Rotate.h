#pragma once
#include "../Headers/olcPixelGameEngine.h"
float deg_to_rad(float angle) {
	return angle * (3.141 / 180);
}
olc::vf2d rot(olc::vf2d input,float angle) {
	olc::vf2d ret;
	ret.x = (input.x * cos(deg_to_rad(angle))) + (input.y * sin(deg_to_rad(angle)));
	ret.y = (input.x * -1*sin(deg_to_rad(angle))) + (input.y * cos(deg_to_rad(angle)));
	return ret;
}