#include "../../GCU.h"
//#include <string>
#include "../../../Utility/UtilFunc.h"
#include "../../../Utility/TextWrap.h"
#include "../TextInput.h"
#include <iostream>
void GCU::AddProjectMenu() {
	if (MenuOptionsAcivationState) {
		overide = 1;
		pUpdate = 0;
		pge->Clear(olc::WHITE);
		std::string title = "Eneter New Project Name";
		pge->DrawString(int((300 - (title.size() * 8)) / 2), 30, title, olc::BLACK);
		pge->DrawRect(ObjectPosition(150, 150, pge, 1), 100, 150, 150, olc::VERY_DARK_GREY);
		if (isPressed(pge)) {
			textIn += KeyEvent(pge);
		}
		std::deque<std::string> strd = DirtyTextWrap(textIn, pge->GetDrawTargetWidth());
		for (unsigned int i = 0; i < strd.size(); i++) {
			pge->DrawStringDecal({ 75,float(i * 8) + 102 }, strd[i], olc::BLACK);
		}
		if (pge->GetKey(olc::ENTER).bPressed) {
			tmppro.name = textIn;
			textIn = "";
			MenuOptionsAcivationState = 0;
			pge->Clear(olc::Pixel(255, 255, 255));
		}
	}
	else {
		overide = 1;
		pUpdate = 0;
		pge->Clear(olc::WHITE);
		std::string title = "Eneter New Project Discription";
		pge->DrawString(int((300 - (title.size() * 8)) / 2), 30, title, olc::BLACK);
		pge->DrawRect(ObjectPosition(150, 150, pge, 1), 100, 150, 150, olc::VERY_DARK_GREY);
		if (isPressed(pge)) {
			textIn += KeyEvent(pge);
		}
		std::deque<std::string> strd = DirtyTextWrap(textIn, pge->GetDrawTargetWidth());
		for (unsigned int i = 0; i < strd.size(); i++) {
			pge->DrawStringDecal({ 75,float(i * 8) + 102 }, strd[i], olc::BLACK);
		}
		if (pge->GetKey(olc::ENTER).bPressed) {
			pUpdate = 1;
			std::cout << tmppro.name << " disc " << textIn<<"\n";
			myDat.addProject(tmppro.name, textIn);
			textIn = "";
			overide = 0;
			menuMode = -1;
			MenuOptionsAcivationState = 1;

			pge->Clear(olc::Pixel(255,255, 255));
		}
	}
}
void GCU::EditProjectMenu(int Index) {
	if (MenuOptionsAcivationState) {
		overide = 1;
		pUpdate = 0;
		pge->Clear(olc::WHITE);
		std::string title = "Eneter New Project Name";
		pge->DrawString(int((300 - (title.size() * 8)) / 2), 30, title, olc::BLACK);
		pge->DrawString(ObjectPosition(14 * 8, 100, pge, 1), 200, "Previos Name: ", olc::BLACK);
		pge->DrawRect(ObjectPosition(150, 150, pge, 1), 100, 150, 150, olc::VERY_DARK_GREY);
		if (isPressed(pge)) {
			textIn += KeyEvent(pge);
		}
		std::deque<std::string> strd = DirtyTextWrap(textIn, pge->GetDrawTargetWidth());
		for (unsigned int i = 0; i < strd.size(); i++) {
			pge->DrawStringDecal({ 75,float(i * 8) + 102 }, strd[i], olc::BLACK);
		}
		if (pge->GetKey(olc::ENTER).bPressed) {
			tmppro.name = textIn;
			textIn = "";
			MenuOptionsAcivationState = 0;
			pge->Clear(olc::Pixel(255, 255, 255));
		}
	}
	else {
		overide = 1;
		pUpdate = 0;
		pge->Clear(olc::WHITE);
		std::string title = "Eneter New Project Discription";
		pge->DrawString(int((300 - (title.size() * 8)) / 2), 30, title, olc::BLACK);
		pge->DrawRect(ObjectPosition(150, 150, pge, 1), 100, 150, 150, olc::VERY_DARK_GREY);
		if (isPressed(pge)) {
			textIn += KeyEvent(pge);
		}
		std::deque<std::string> strd = DirtyTextWrap(textIn, pge->GetDrawTargetWidth());
		for (unsigned int i = 0; i < strd.size(); i++) {
			pge->DrawStringDecal({ 75,float(i * 8) + 102 }, strd[i], olc::BLACK);
		}
		if (pge->GetKey(olc::ENTER).bPressed) {
			pUpdate = 1;
			std::cout << tmppro.name << " disc " << textIn << "\n";
			myDat.addProject(tmppro.name, textIn);
			textIn = "";
			overide = 0;
			menuMode = -1;
			MenuOptionsAcivationState = 1;

			pge->Clear(olc::Pixel(255, 255, 255));
		}
	}
}
void GCU::DeleteProjectMenu(int Index) {
	overide = 1;

}