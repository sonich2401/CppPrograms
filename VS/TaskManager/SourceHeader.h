#pragma once
#include "projectDatabase.h"
#include "olcPixelGameEngine.h"
#include "TextWrap.h"

#include <deque>
#include <string>
#include <iostream>

using std::deque;
using std::string;

class fakeclass {
public:
	database data;
	void loadData() {
		data.loadDatabase();
	}
	olc::PixelGameEngine* pge;
	void listProjects(float x,float y,float yoff,string title) {
		olc::vf2d pos= { x,y };
		olc::vi2d size = { 75,125 };
		pge->FillRect(pos, size, olc::GREY);
		pge->DrawRect(pos, size, olc::DARK_GREY);
		pos = { x + 4,y - 9 };
		pge->DrawString(pos,title,olc::BLACK);
		size = {71,25};
		for (unsigned int i = 0; i < data.Dat.size(); i++) {
			pos = { (x + 2),(y + 2) + i*(size.y+1) };
			pge->FillRect(pos, size, olc::WHITE);
			pge->DrawRect(pos, size, olc::BLACK);
			pos = { pos.x + 4,pos.y + 2 };
			deque<string> tmpd = simpTextWrap(size.x, data.Dat[i].name,7);
		//	std::cout << tmpd.front();
			for (unsigned int i1 = 0; i1 < tmpd.size(); i1++) {
				olc::vf2d tmppos = {pos.x,pos.y+(i1*8)};
				pge->DrawString(tmppos, tmpd[i1], olc::VERY_DARK_GREY);
			}
		}
	}
	void listRegion(float x, float y, float yoff, string title,unsigned int index) {
		olc::vf2d pos = { x,y };
		olc::vi2d size = { 75,125 };
		pge->FillRect(pos, size, olc::GREY);
		pge->DrawRect(pos, size, olc::DARK_GREY);
		pos = { x + 4,y - 9 };
		pge->DrawString(pos, title, olc::BLACK);
		size = { 71,25 };
		for (unsigned int i = 0; i < data.Dat[index].Dat.size(); i++) {
			pos = { (x + 2),(y + 2) + i * (size.y + 1) };
			pge->FillRect(pos, size, olc::WHITE);
			pge->DrawRect(pos, size, olc::BLACK);
			pos = { pos.x + 4,pos.y + 2 };
			deque<string> tmpd = simpTextWrap(size.x, data.Dat[index].Dat[i].name,6);
			for (unsigned int i1 = 0; i1 < tmpd.size(); i1++) {
				olc::vf2d tmppos = { pos.x,pos.y + (i1 * 8) };
				pge->DrawString(tmppos, tmpd[i1], olc::VERY_DARK_GREY);
			}
		}
	}
	void listTasks(float x, float y, string title, unsigned int index, unsigned int index1) {
		olc::vf2d pos = { x,y };
		olc::vi2d size = { 75,125 };
		pge->FillRect(pos, size, olc::GREY);
		pge->DrawRect(pos, size, olc::DARK_GREY);
		pos = { x + 4,y - 9 };
		pge->DrawString(pos, title, olc::BLACK);
		size = { 71,25 };
		for (unsigned int i = 0; i < data.Dat[index].Dat[index1].Dat.size(); i++) {
			pos = { (x + 2),(y + 2) + i * (size.y + 1) };
			pge->FillRect(pos, size, olc::WHITE);
			pge->DrawRect(pos, size, olc::BLACK);
			pos = { pos.x + 4,pos.y + 2 };
			deque<string> tmpd = simpTextWrap(size.x, data.Dat[index].Dat[index1].Dat[i].name, 5);
			for (unsigned int i1 = 0; i1 < tmpd.size(); i1++) {
				olc::vf2d tmppos = { pos.x,pos.y + (i1 * 8) };
				pge->DrawString(tmppos, tmpd[i1], olc::VERY_DARK_GREY);
			}
		}

	}
	void taskVeiw(unsigned int index, unsigned int index1,unsigned int index3) {
		pge->DrawString({ 125,0 }, "Task Info", olc::BLACK);
		pge->DrawString({ 135,7 }, "______", olc::BLACK);
	}
	void addDataToSave(string proName,string proDisc,string regName,string regDisc,string taskName,string taskDisc,bool st) {
		project tmppro;
		tmppro.name = proName;
		tmppro.discription = proDisc;
		region tmpreg;
		tmpreg.name = regName;
		tmpreg.discription = regDisc;
		task tmptask;
		tmptask.name = taskName;
		tmptask.discription = taskDisc;
		tmpreg.Dat.push_back(tmptask);
		tmppro.Dat.push_back(tmpreg);
		data.Dat.push_back(tmppro);
		data.saveDatabase();
	}
	template <class T>
	void discription(float x, float y, T obj) {
		olc::vf2d pos = { x + 4,y };
		pge->DrawString(pos, "Discription", olc::BLACK);
		pos = { x,y + 8 };
		pge->DrawRect(pos, { 180,125 }, olc::BLACK);
		listDisc(obj.discription,x,y);
	}
	database* getDat() {
		return &data;
	}
	unsigned int getPro() {
		return data.Dat.size();
	}
	unsigned int getReg(string project) {
		return data.getProject(project)->Dat.size();
	}
	unsigned int getTask(string project, string region) {
		return data.getRegion(project, region)->Dat.size();
	}
	void drawTime(date* p, bool st = 0) {
		int bol = st;
		string text[2] = { "Date Created:","Date Modified:" };
		pge->DrawString({ 20+(bol*150),200 }, text[bol], olc::BLACK);
		int strint[6] = { p->mm ,p->dd ,p->yyyy,p->hr,p->min,p->sec };
        string tmpstr;
		for (unsigned int v = 0; v < 2; v++) {
			for (unsigned int i = 0; i < std::to_string(strint[v]).size(); i++) {
				tmpstr += std::to_string(strint[v])[i];
			}
			tmpstr += "/";
		}
		//tmpstr += "2";
		for (unsigned int i = 1; i < std::to_string(strint[2]).size(); i++) {
			tmpstr += std::to_string(strint[2])[i];
		}
		pge->DrawString({ 30 + (bol * 150),220 }, tmpstr,olc::VERY_DARK_GREY);
		tmpstr = "";
		for (unsigned int v = 3; v < 5; v++) {
			for (unsigned int i = 0; i < std::to_string(strint[v]).size(); i++) {
				tmpstr += std::to_string(strint[v])[i];
			}
			tmpstr += ":";
		}
		for (unsigned int i = 0; i < std::to_string(strint[5]).size(); i++) {
			tmpstr += std::to_string(strint[5])[i];
		}
		pge->DrawString({ 30 + (bol * 150),230 }, tmpstr, olc::VERY_DARK_GREY);

	}
private:
	void listDisc(string str,float x,float y) {
		olc::vf2d pos;
	deque<string> tmpd = textwrap(x + 4, y + 4, 180, 125, str);
		for (unsigned int i = 0; i < tmpd.size(); i++) {
			pos = { x + 4,(y + 11) + (i * 10) };
			pge->DrawString(pos, tmpd[i], olc::VERY_DARK_GREY);
		}
	}
};