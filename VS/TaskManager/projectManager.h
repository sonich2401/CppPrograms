#pragma once

#include "ProjectTemplate.h"

#include <map>
#include <string>
#include <deque>

class project {
public:
	project();
	void addSection(std::string SectionName, std::string discript = "");
	void delSection(std::string SectionName);
	void addTask(std::string TaskName, std::string SectionName, bool state=0, std::string disr = "");
	void delTask(std::string TaskName, std::string SectionName);
	task *getTask(std::string SectionName, std::string TaskName);
	region *getRegion(std::string SectionName);
	void sRegion(region newRegion);
	std::deque<region>* getprojectdat() {
		return &Dat;
	}
	date created;
    date modified;
	std::string name;
	std::string discription;
	std::deque<region> Dat;
};