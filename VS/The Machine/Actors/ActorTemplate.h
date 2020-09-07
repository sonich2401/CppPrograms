#pragma once
#include "../Headers/olcPixelGameEngine.h"
#include "../Headers/Sprite.h"
struct actor {
	olc::PixelGameEngine* pge;
	olc::vf2d pos;
	olc::vf2d vel;
	olc::vf2d home;
	pge::ren* spr;
};