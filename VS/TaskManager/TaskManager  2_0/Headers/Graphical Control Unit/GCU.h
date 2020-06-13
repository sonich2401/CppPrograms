#pragma once
#include "../DatabaseControl/Database.h"
#include "olcPixelGameEngine.h"
#include "../Structs/NeededLib.h"
class GCU {
public:
	bool st[100];
#define overide st[0]
#define pUpdate st[1]
#define MenuOptionsAcivationState st[2]
public:
	database myDat;
	GCU(olc::PixelGameEngine* _pge);
	olc::PixelGameEngine* pge;
public:
	template <class T>
	void ListItems(T* obj);
	template <class T>
	void ListDiscription(T* obj);
public:
	void menuOptions(int Index[3]);
	int GlobalButtonCheck();
private:
	void AddProjectMenu();
	void DeleteProjectMenu(int Index);
	void EditProjectMenu(int Index);
private:
	void AddRegionMenu(int Index1);
	void EditRegionMenu(int Index1 ,int Index2);
	void DeleteRegionMenu(int Index1, int Index2);
private:
	void AddTaskMenu(int Index1,int Index2);
	void DeleteTaskMenu(int Index[3]);
	void EditTaskMenu(int Index[3]);
private:
	int menuMode = -1;
	std::string textIn;
private:
	project tmppro;
	region tmpreg;
	task tmptsk;
};

template<class T>
inline void GCU::ListItems(T* obj)
{
	pge->DrawRect(20, 40, 75, 150, olc::BLACK);
	pge->FillRect(21, 41, 72, 148, olc::GREY);
	for (unsigned int i = 0; i < obj->Dat.size(); i++) {
		//pge->drawrect();
		obj->Dat[i].name;
	}
}

template<class T>
inline void GCU::ListDiscription(T* obj)
{
}
