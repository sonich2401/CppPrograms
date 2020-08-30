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
bool RectInRect(olc::vf2d& pos1, olc::vf2d size1, olc::vf2d& pos2, olc::vf2d size2) {
	return pointInRect(pos1, pos2, size2) || pointInRect(size1 + pos1, pos2, size2) || pointInRect({ pos1.x,pos1.y + size1.y }, pos2, size2) || pointInRect({pos1.x+size1.x,pos1.y}, pos2, size2);
}
bool LineInRect(olc::vf2d p1, olc::vf2d p2, olc::vf2d pos, olc::vf2d size) {
	return pointInRect(p1, pos, size) || pointInRect(p1, pos, size);
}
float GetDistance(olc::vf2d p1, olc::vf2d p2) {
	return sqrt(((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y)));
}
std::vector<olc::vf2d> getPoints(olc::vf2d& pos, olc::vf2d& size) {
	return std::vector<olc::vf2d>() = { {pos},{pos.x,pos.y+size.y},{pos.x+size.x,pos.y},{pos+size} };
}
//struct Room {
//	unsigned int* colDat;
//	unsigned int* gfxDat;
//	unsigned int roomWidth;
//	void deleteRoom() {
//		delete[] colDat;
//		delete[] gfxDat;
//	}
//	template <size_t w, size_t h>
//	void loadRoom(const unsigned int var[w][h]) {
//		roomWidth = w;
//		colDat = new unsigned int[w * h];
//		for (unsigned int x = 0; x < w; x++)
//			for (unsigned int y = 0; y < h; y++)
//				colDat[(x * w) + y] = var[x][y];
//	}
//	unsigned int VeiwDat(unsigned int x, unsigned int y) {
//		return colDat[(x * roomWidth) + y];
//	}
//	~Room() {
//		this->deleteRoom();
//	}
//
//};
//struct ColBox {
//	olc::vf2d pos;
//	olc::vf2d size;
//	ColBox(olc::vf2d _pos,olc::vf2d _size) {
//		pos = _pos;
//		size = _size;
//	}
//	float TopCol(olc::vf2d& pos, olc::vf2d& size) {
//		float offset=0;
//		if (RectInRect(pos, size, this->pos, this->size)) {
//			std::vector<olc::vf2d> points = { {pos.x,pos.y + size.y},{pos + size} };
//			for (auto p : points) {
//				if(pointInRect(p, this->pos, this->size))
//					offset = (this->pos.y - pos.y - size.y) ;
//			}
//		}
//		return offset;
//	}
//	float BottomCol(olc::vf2d& pos, olc::vf2d& size) {
//		float offset=0;
//		if (RectInRect(pos, size, this->pos, this->size)) {
//			std::vector<olc::vf2d> points = { {pos.x + size.x,pos.y},{pos} };
//			for (auto p : points) {
//				if (pointInRect(p, this->pos, this->size))
//					offset = ((this->pos.y+this->size.y) - pos.y);
//			}
//		}
//		return offset;
//	}
//	float LeftCol(olc::vf2d& pos, olc::vf2d& size) {
//		float offset=0;
//		if (RectInRect(pos, size, this->pos, this->size)) {
//			std::vector<olc::vf2d> points = { {pos.x+size.x,pos.y},{pos + size} };
//			for (auto p : points) {
//				if (pointInRect(p, this->pos, this->size))
//					offset = (this->pos.x - pos.x - size.x);
//			}
//		}
//		return offset;
//	}
//	float RightCol(olc::vf2d& pos, olc::vf2d& size) {
//		float offset=0;
//		if (RectInRect(pos, size, this->pos, this->size)) {
//			std::vector<olc::vf2d> points = { {pos.x,pos.y},{pos.x,pos.y+size.y} };
//			for (auto p : points) {
//				if (pointInRect(p, this->pos, this->size))
//					offset = ((this->pos.x + this->size.x) - pos.x);
//			}
//		}
//		return offset;
//	}
//	olc::vf2d collide(olc::vf2d& pos, olc::vf2d& size) {
//		olc::vf2d ret;
//		return ret;
//	}
//};
//struct Room {
//	std::vector<ColBox> colDat;
//};
//
struct ColBox {
	unsigned short int x;
	unsigned short int y;
	unsigned short int w;
	unsigned short int h;
	float GetYInersection(olc::vf2d &pos, olc::vf2d &lastPos, float y ) {
		if (lastPos.x == pos.x)
			return lastPos.x;
		float s = getSlope<float>(pos.x, pos.y, lastPos.x, lastPos.y);
		float b = getB<float>(pos.x, pos.y,s);
		float x = (y - b) / s;
		return x;
	}
	float GetXInersection(olc::vf2d& pos, olc::vf2d& lastPos, float x) {
		float s = getSlope<float>(pos.x, pos.y, lastPos.x, lastPos.y);
		float b = getB<float>(pos.x, pos.y, s);
		float y = (s*x)+b;
		return y;
	}
	bool pointInRect(olc::vf2d &point,olc::vf2d &pos,olc::vf2d &size) {
		return (point.x >= pos.x) && (point.y >= pos.y) && (point.x <= pos.x + size.x) && (point.y <= pos.y + size.y);
	}
	bool pointInLine(olc::vf2d &point, olc::vf2d &p1,olc::vf2d &p2) {
		
	}
	bool RectInsideLine(olc::vf2d &pos,olc::vf2d &size,olc::vf2d &linePos,float lineSize) {
	
	}
	void Collision(olc::vf2d * Pos,olc::vf2d * vel,olc::vf2d size,olc::PixelGameEngine *pge) {
		olc::vf2d offset,nextPos,CurPos;
		nextPos =  *vel + *Pos;
		CurPos = *Pos;
		bool tb=0;
		//pge->DrawStringDecal({ 0,0 }, "X: "+std::to_string(GetYInersection(nextPos,vel,this->y)), olc::BLACK);
		//pge->DrawStringDecal({ 100,0 }, "Y: " + std::to_string(GetXInersection(nextPos, vel, this->x)), olc::BLACK);
		//pge->DrawStringDecal({ 0,10 }, "X: " + std::to_string(GetYInersection(nextPos, vel, this->y+h)), olc::BLACK);
		//pge->DrawStringDecal({ 100,10 }, "Y: " + std::to_string(GetXInersection(nextPos, vel, this->x+w)), olc::BLACK);
		if ((CurPos.y < y -size.y&& nextPos.y  > y-size.y)) {
			float xin = GetYInersection(nextPos, CurPos, this->y);

			if ((xin - x+size.x+size.x>= 0 && xin-x-size.x <= w)) {
				Pos->y = y - size.y-0.01;
				vel->y = 0;
				tb = 1;
			}
		}
		if (CurPos.y > y + h && nextPos.y < y+h) {
			float xin = GetYInersection(nextPos, CurPos, this->h + this->y);
			if (xin - x + size.x>= 0 && xin-x <= w) {
				Pos->y = this->y + this->h + 0.01;
				vel->y = 0;
				tb = 1;
			}
		}
		if (!tb) {
			if (CurPos.x < x - size.x && nextPos.x>x - size.x) {
				float yin = GetXInersection(nextPos, CurPos, this->y);
				if (yin - y + size.y + size.y >= 0 && yin - y - size.y <= h) {
					Pos->x = x - 0.01 - size.x;
					vel->x = 0;
				}
			}
			if (CurPos.x > x + w && nextPos.x < x + w) {
				float yin = GetXInersection(nextPos, CurPos, this->h + this->y);
				if (yin - y + size.y >= 0 && yin - y <= h) {
					Pos->x = (x + w) + 0.01;
					vel->x = 0;
				}
			}
		}
	}
};
