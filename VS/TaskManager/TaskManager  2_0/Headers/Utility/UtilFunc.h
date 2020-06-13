#pragma once
//#define lend '\n'
//#define rl '\r'
//#define iter0(x) for(unsigned int i=0;i<x;i++)
//#define iter1(x) for(unsigned int i1=0;i1<x;i1++)
//#define iter2(x) for(unsigned int i2=0;i2<x;i2++)
//#define forRange(b,e) for(unsigned int r=b;r<e;r++)
#include <deque>
#include <string>
#include "../Graphical Control Unit/olcPixelGameEngine.h"
inline int ObjectPosition(int width,int height,int areaWidth,int areaHeight,int numOfObjects=1) {
	return 0;
}
inline int ObjectPosition(int width, int height, olc::PixelGameEngine* pge, int numOfObjects = 1) {
	return int((pge->GetDrawTargetWidth()-width)/(numOfObjects+1));
}
inline std::deque<std::string> TextWrap(){
	std::deque<std::string> tmpstrd;
	return tmpstrd;
}