#include "projectManager.h"
#include <fstream>
#include <iostream>

project::project()
{
	created.update();
	modified.update();
}

void project::addSection(std::string SectionName,std::string discript)
{
	region tmpregion;
	tmpregion.created.update();
	tmpregion.modified.update();
	modified.update();
	Dat.push_back(tmpregion);
}

void project::delSection(std::string SectionName)
{
	for (unsigned int i = 0; i < Dat.size(); i++) {
		if (Dat[i].name==SectionName){
			Dat.erase(Dat.begin()+i);
		}
	}
	modified.update();
}

void project::addTask(std::string TaskName, std::string SectionName, bool state, std::string disr)
{
	modified.update();
	for (unsigned int i = 0; i < Dat.size(); i++) {
		if (Dat[i].name == SectionName) {
			task tmptask;
			tmptask.created.update();
			tmptask.modified.update();
			tmptask.discription = disr;
			tmptask.st = state;
			tmptask.name = TaskName;
			Dat[i].modified.update();
			Dat[i].Dat.push_back(tmptask);
		}
	}
}

void project::delTask(std::string TaskName, std::string SectionName)
{
	for (unsigned int i = 0; i < Dat.size(); i++) {
		if (Dat[i].name == SectionName) {
			for (unsigned int i2 = 0; i2 < Dat.size(); i++) {
				if (Dat[i].Dat[i2].name == TaskName) {
					Dat[i].Dat.erase(Dat[i].Dat.begin() + i2);
				}
			}
			Dat[i].modified.update();
		}
	}
	modified.update();
}

task *project::getTask(std::string SectionName, std::string TaskName)
{
	for (unsigned int i = 0; i < Dat.size(); i++) {
		if (Dat[i].name == SectionName) {
			for (unsigned int i1 = 0; i1 < Dat[i].name.size(); i++) {
				if (Dat[i].Dat[i1].name==TaskName) {
					return &Dat[i].Dat[i1];
				}
			}
		}
	}
}

region *project::getRegion(std::string SectionName)
{
	for (unsigned int i = 0; i < Dat.size(); i++) {
		if (Dat[i].name == SectionName) {
			return &Dat[i];
		}
	}
}

void project::sRegion(region newRegion)
{
	Dat.push_back(newRegion);
}
