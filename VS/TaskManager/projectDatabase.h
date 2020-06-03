#pragma once
#include <deque>
#include "projectManager.h"
class database {
public:
	database();
	void addProject(std::string ProjectName,std::string discription);
	void delProject(std::string ProjectName);
	void saveDatabase();
	void loadDatabase();
	project* getProject(std::string ProjectName);
	//TODO Maybe dont inlcude these functions????
	region* getRegion(std::string ProjectName, std::string RegionName);
	task* getTask();
	std::deque<project> Dat;
private:
	unsigned int totalProjects;
};