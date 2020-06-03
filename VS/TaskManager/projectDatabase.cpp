#include "projectDatabase.h"
#include "sb.h"
#include <string>
#include <iostream>

//helperDefinitions
#define incer ++curline
#define dline(x) sb::readline("C://Users/mener/OneDrive/Desktop/C++ Testing/TaskManager/Debug/sav.pds",x)
#define rline(y) sb::writeLine(incer,y,"C://Users/mener/OneDrive/Desktop/C++ Testing/TaskManager/Debug/sav.pds")
#define l_pro Dat.front()
#define l_reg l_pro.getprojectdat()
#define l_tsk l_reg->front().Dat
int curline = 0;
database::database()
{
	//database::loadDatabase();
}

void settime(date *p) {
	p->dd = std::stoi(dline(incer));
	p->mm = std::stoi(dline(incer));
	p->yyyy = std::stoi(dline(incer));
	p->hr = std::stoi(dline(incer));
	p->min = std::stoi(dline(incer));
	p->sec = std::stoi(dline(incer));
}
void settime1(date* p) {
	rline(std::to_string(p->dd));
	rline(std::to_string(p->mm));
	rline(std::to_string(p->yyyy));
	rline(std::to_string(p->hr));
	rline(std::to_string(p->min));
	rline(std::to_string(p->sec));
}

void database::addProject(std::string ProjectName, std::string discription)
{
	//add a new Project to the Project Database
	project tmpProject;
	tmpProject.discription = discription;
	tmpProject.name = ProjectName;
	Dat.push_back(tmpProject);
}
void database::delProject(std::string ProjectName)
{
	//Delete a Specified Project
}
project* database::getProject(std::string ProjectName)
{
	for(unsigned int i=0;i<Dat.size();i++){
		if (Dat[i].name==ProjectName){
			return &Dat[i];
		}
	}
	return nullptr;
}



//TODO Maybe Dont include these functions????
region* database::getRegion(std::string ProjectName, std::string RegionName)
{
	this->getRegion(ProjectName, RegionName);
	return nullptr;
}

task* database::getTask()
{
	return nullptr;
}

void database::loadDatabase()
{
	if (dline(1) != "") {
		int project_c = 0;
		totalProjects = std::stoi(dline(++curline));
		for (unsigned int i1 = 0; i1 < totalProjects; i1++) {
			project tmpProject;
			tmpProject.name = dline(incer);
			tmpProject.discription = dline(incer);
			settime(&tmpProject.created);
			settime(&tmpProject.modified);
			unsigned int totalRegions = std::stoi(dline(incer));
			for (unsigned int i = 0; i < totalRegions; i++) {
				region tmpRegion;
				tmpRegion.name = dline(incer);
				tmpRegion.discription = dline(incer);
				settime(&tmpRegion.created);
				settime(&tmpRegion.modified);
				unsigned int totalTasks = std::stoi(dline(incer));
				for (unsigned int i2 = 0; i2 < totalTasks; i2++) {
					task tmpTask;
					tmpTask.name = dline(incer);
					tmpTask.discription = dline(incer);
					settime(&tmpTask.created);
					settime(&tmpTask.modified);
					tmpTask.st = std::stoi(dline(incer));
					tmpRegion.Dat.push_back(tmpTask);
				}
				tmpProject.sRegion(tmpRegion);
			}
			Dat.push_back(tmpProject);
		}
		curline = 0;	
	}
}
void database::saveDatabase()
{
	sb::init("C://Users/mener/OneDrive/Desktop/C++ Testing/TaskManager/Debug/sav.pds");
	const unsigned int sizes[4] = { Dat.size(),l_reg->size(),l_tsk.size(),l_pro.Dat.size() };
	rline(std::to_string(sizes[0]));
	for (unsigned int i = 0; i < sizes[0]; i++) {
		rline(l_pro.name);
		rline(l_pro.discription);
		settime1(&l_pro.created);
		settime1(&l_pro.modified);
		rline(std::to_string(sizes[1]));
		for (unsigned int i1 = 0; i1 < sizes[1]; i1++) {
			rline(l_reg->front().name);
			rline(l_reg->front().discription);
			settime1(&l_reg->front().created);
			settime1(&l_reg->front().modified);
			rline(std::to_string(sizes[2]));
			for (unsigned int i2 = 0; i2 < sizes[2]; i2++) {
				rline(l_tsk.front().name);
				rline(l_tsk.front().discription);
				settime1(&l_tsk.front().created);
				settime1(&l_tsk.front().modified);
				rline(std::to_string(int(l_tsk.front().st)));
				l_tsk.pop_front();
			}
			l_reg->pop_front();
		}
		Dat.pop_front();
	}
}

