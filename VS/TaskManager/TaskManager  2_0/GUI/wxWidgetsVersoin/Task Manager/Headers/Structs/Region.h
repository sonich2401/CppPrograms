#pragma once
#include "NeededLib.h"
#include "Task.h"
struct region {
	region() {
		created.update();
		modified.update();
	}
	string name;
	string discription;
	date created;
	date modified;
	deque<task> Dat;
};