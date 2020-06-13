#pragma once
#include "NeededLib.h"
#include "Region.h"
struct project {
	project() {
		created.update();
		modified.update();
	}
	string name;
	string discription;
	date created;
	date modified;
	deque<region> Dat;
};