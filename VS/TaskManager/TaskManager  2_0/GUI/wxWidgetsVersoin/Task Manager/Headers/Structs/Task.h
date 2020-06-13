#pragma once
#include "NeededLib.h"
struct task {
	task() {
		created.update();
		modified.update();
	}
	string name;
	string discription;
	date created;
	date modified;
	bool state=false;
};