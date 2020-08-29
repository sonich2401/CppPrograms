#pragma once
#include "./olcPixelGameEngine.h"
void crash() {
	std::vector<char> a;
	a[1]=1;
}
//! OLD COLLISION CODE
template <typename T>
float getSlope(T x1,T y1,T x2,T y2) {
	return (y2 - y1) / (x2 - x1);
}
template <typename T>
float getB(T px,T py,float s) {
	return py - (s * px);
}
bool pointInRect(olc::vf2d point, olc::vf2d& pos, olc::vf2d& size) {
	return (point.x >= pos.x) && (point.y >= pos.y) && (point.x <= pos.x + size.x) && (point.y <= pos.y + size.y);
}
bool RectInRect(olc::vf2d& pos1, olc::vf2d& size1, olc::vf2d& pos2, olc::vf2d& size2) {
	return pointInRect(pos1, pos2, size2) || pointInRect(size1 + pos1, pos2, size2) || pointInRect({ pos1.x,pos1.y + size1.y }, pos2, size2) || pointInRect({pos1.x+size1.x,pos1.y}, pos2, size2);
}
//
//struct ColBox {
//	unsigned short int x;
//	unsigned short int y;
//	unsigned short int w;
//	unsigned short int h;
//	float GetYInersection(olc::vf2d &pos, olc::vf2d &lastPos, float y ) {
//		if (lastPos.x == pos.x)
//			return lastPos.x;
//		float s = getSlope<float>(pos.x, pos.y, lastPos.x, lastPos.y);
//		float b = getB<float>(pos.x, pos.y,s);
//		float x = (y - b) / s;
//		return x;
//	}
//	float GetXInersection(olc::vf2d& pos, olc::vf2d& lastPos, float x) {
//		float s = getSlope<float>(pos.x, pos.y, lastPos.x, lastPos.y);
//		float b = getB<float>(pos.x, pos.y, s);
//		float y = (s*x)+b;
//		return y;
//	}
//	bool pointInRect(olc::vf2d &point,olc::vf2d &pos,olc::vf2d &size) {
//		return (point.x >= pos.x) && (point.y >= pos.y) && (point.x <= pos.x + size.x) && (point.y <= pos.y + size.y);
//	}
//	bool pointInLine(olc::vf2d &point, olc::vf2d &p1,olc::vf2d &p2) {
//		
//	}
//	bool RectInsideLine(olc::vf2d &pos,olc::vf2d &size,olc::vf2d &linePos,float lineSize) {
//	
//	}
//	void Collision(olc::vf2d * Pos,olc::vf2d& vel,olc::vf2d size,olc::PixelGameEngine *pge) {
//		olc::vf2d offset,nextPos,CurPos;
//		nextPos = *Pos;
//		CurPos = vel;
//		pge->DrawStringDecal({ 0,0 }, "X: "+std::to_string(GetYInersection(nextPos,vel,this->y)), olc::BLACK);
//		pge->DrawStringDecal({ 100,0 }, "Y: " + std::to_string(GetXInersection(nextPos, vel, this->x)), olc::BLACK);
//		pge->DrawStringDecal({ 0,10 }, "X: " + std::to_string(GetYInersection(nextPos, vel, this->y+h)), olc::BLACK);
//		pge->DrawStringDecal({ 100,10 }, "Y: " + std::to_string(GetXInersection(nextPos, vel, this->x+w)), olc::BLACK);
//		if ((CurPos.y < y -size.y&& nextPos.y  > y-size.y)) {
//			float xin = GetYInersection(nextPos, CurPos, this->y);
//			std::cout << xin + size.x<<"\n";
//			if ((xin - x >= 0 && xin - x <= w)|| (xin - x+size.x >= 0 && xin - x +size.x<= w)) {
//				//std::cout << "\nINERECET_TOP: " << xin << "\n";
//				//offset.y = y-nextPos.y-size.y;
//				//offset.y = y - nextPos.y-size.y;
//				Pos->y = y - size.y-1;
//				//std::cout << "NextPos: " << nextPos.y << " Offset: " << y - nextPos.y - size.y<<"\n";
//				//vel->y = 0;
//			}
//		}
//		if (CurPos.y > y + h && nextPos.y < y+h) {
//			float xin = GetYInersection(nextPos, CurPos, this->h + this->y);
//			if (xin - x >= 0 && xin-x <= w) {
//				std::cout << "\nINERECET_BOTTOM: " << xin << "\n";
//				offset.y = (y+h) - nextPos.y;
//				//vel->y = 0;
//			}
//		}
//		if (CurPos.x < x && nextPos.x>x) {
//			float yin = GetXInersection(nextPos, CurPos, this->y);
//			if (yin - y >= 0 && yin <= h) {
//				std::cout << "\nINERECET_LEFT: " << yin << "\n";
//				offset.x = x - nextPos.x;
//				//vel->x = 0;
//			}
//		}
//		if (CurPos.x > x+w && nextPos.x < x+w) {
//			float yin = GetXInersection(nextPos, CurPos, this->h + this->y);
//			if (yin - y >= 0 && yin <= h) {
//				std::cout << "\nINERECET_RIGHT: " << yin << "\n";
//				offset.x = (x + w) - nextPos.x;
//				//vel->x = 0;
//			}
//		}
//		if (offset.x != 0 || offset.y != 0) {
//			std::cout << offset.x << ":" << offset.y << "\n";
//			//crash();
//		}
//		Pos->x += offset.x;
//		Pos->y += offset.y;
//	}
//};
struct Room {
	unsigned int* colDat;
	unsigned int* gfxDat;
	void deleteRoom() {
		delete[] colDat;
		delete[] gfxDat;
	}
	template <size_t w, size_t h>
	void loadRoom(const unsigned int var[w][h]) {
		colDat = new unsigned int[w * h];
		for (unsigned int x = 0; x < w; x++)
			for (unsigned int y = 0; y < h; y++)
				colDat[(x * w) + y] = var[x][y];
	}
	unsigned int VeiwDat(unsigned int& x, unsigned int& y, unsigned int width) {
		return colDat[(x * width) + y];
	}
	~Room() {
		this->deleteRoom();
	}

};