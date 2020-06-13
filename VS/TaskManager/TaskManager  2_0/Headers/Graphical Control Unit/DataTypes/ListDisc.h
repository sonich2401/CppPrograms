#pragma once
#include "../olcPixelGameEngine.h"
template <class T>
inline int listProjects(float x, float y, int yoff, std::string title,olc::PixelGameEngine* pge,T *obj,int *sel) {
	olc::vf2d pos = { x,y };
	olc::vi2d size = { 75,125 };
	pge->FillRect(pos, size, olc::GREY);
	pge->DrawRect(pos, size, olc::DARK_GREY);
	pos = { x + 4,y - 9 };
	pge->DrawString(pos, title, olc::BLACK);
	size = { 71,25 };
	for (unsigned int i = 0; i < obj->Dat.size(); i++) {
		pos = { (x + 2),(y + 2) + i * (size.y + 1) };
		pge->FillRect(pos, size, olc::WHITE);
		pge->DrawRect(pos, size, olc::BLACK);
		if (pge->GetMouse(0).bPressed) {
			if (pge->GetMouseX() > x&& pge->GetMouseX() < x + 75) {
				if (y + ((i) * 25) < pge->GetMouseY() && y + ((i + 1) * 25) > pge->GetMouseY()) {
					*sel = i;
					return i + yoff;
				}
			}
		}
		if(*sel!=-1&&*sel==i){
			pge->DrawRect(pos.x - 1, pos.y - 1, size.x + 2, size.y + 2, olc::BLUE);
		}
		pos = { pos.x + 4,pos.y + 2 };
		if (i + yoff < obj->Dat.size()) {
			pge->DrawString(pos, obj->Dat[i + yoff].name, olc::VERY_DARK_GREY);
		}
	}
	return -1;
}