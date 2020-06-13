#pragma once
#include "../olcPixelGameEngine.h"
#include <iostream>
inline const char KeyEvent(olc::PixelGameEngine* pge) {
	const char alf[27] = { NULL,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	for (int i = 1; i < 27; i++) {
		if (pge->GetKey(olc::Key(i)).bPressed) {
			return alf[i];
		}
	}
	if (pge->GetKey(olc::Key(84)).bPressed) {
		return '.';
	}
	if (pge->GetKey(olc::Key(53)).bPressed) {
		return ' ';
	}
	return NULL;
}
inline bool isPressed(olc::PixelGameEngine *pge) {
	if (KeyEvent(pge) != NULL)
		return 1;
	else
		return 0;
}