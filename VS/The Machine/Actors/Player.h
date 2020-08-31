#pragma once
#include "../Headers/olcPixelGameEngine.h"
#include "../Headers/Sprite.h"
struct Player {
	olc::vf2d pos;
	olc::vf2d size;
	pge::ren * spr;
	~Player() {
		delete spr;
	}
	struct stam {
		float val;
		float min;
		float max;
		float timer;
		float Dspeed;
		float Rspeed;
		bool refueling;
		void UseStamina() {
			val -= !refueling * Dspeed;
			val += refueling * Rspeed;
		}
		bool BelowTreshold() {
			return val < min;
		}

	}stam;
	
};