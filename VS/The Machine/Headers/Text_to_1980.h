#pragma once
#include "./olcPixelGameEngine.h"
#include "./Sprite.h"
#include <bitset>
struct Monitor {
	std::vector<std::string>Display;
	std::vector<pge::ren>Font;
	olc::PixelGameEngine* pge;
	uint8_t CurLine=0;
	float timer=0;
	Monitor(olc::PixelGameEngine * olc) {
		//Start the PGE
			pge = olc;
		//Load Font

		
	}
	Monitor() {
		//Start the PGE
		//Load Font
		for(unsigned int i=0;i<20;i++)
			Display.push_back(">");

	}
	void Cout(std::string &txt,uint8_t ) {
		
	}
	void AppText(std::string text, unsigned char line_num) {
		std::cout << (int)line_num << "\n";
		if (Display.size() < line_num)
			Display.push_back(text);
		else
			Display[line_num].append(text);
	}
	void ClearText(uint8_t line_num) {
		Display[line_num] = "";
	}
	void DrawCursor() {
		
	}
};