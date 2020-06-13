#pragma once
#include <string>
#include <deque>
#include "../Structs/Project.h"
using std::string;
using std::deque;
class database {
public:
	database();
	void saveDatabase(string saveFileName);
	void loadDatabase(string saveFileName = "./sav.pds");
	void addProject(string projectName, string _discription);
	bool editProject(string projectName, string newProjectName, string newDiscription);
	bool delProject(string projectName);
	void addRegion(string projectName, string regionName, string regionDiscription);
	bool editRegion(string projectName, string regionName, string newRegionName, string newRegionDiscription);
	bool delRegion(string projectName, string regionName);
	void addTask(string projectName, string regionName, string taskName, string taskDiscription);
	bool editTask(string projectName, string regionName, string taskName, string newTaskName, string newTaskDiscription);
	bool delTask(string projectName, string regionName, string taskName);
	//olc::PixelGameEngine* pge;
	deque<project> Dat;
private:
	int curline = 0;
	int totalProjects = 0;
	int totalRegions = 0;
	int totalTasks = 0;
	void settime(date* obj, string fn);
	template <class T>
	unsigned int Indexer(T* obj, string name);


	//TODO THIS IS NOT A TODO BUT IS A NOTE: Hello this is info added for helping wxWidgets display the database information
public:
	std::deque <project> getProject();
	std::deque <region> getRegion(int ProjectId);
	std::deque <task> getTask(int ProjectId, int RegionId);
};
template<class T>
inline unsigned int database::Indexer(T* obj, string name)
{
	for (unsigned int i = 0; i < obj->Dat.size(); i++) {
		if (obj->Dat[i].name == name) {
			return i;
		}
	}
	return -1;
}
