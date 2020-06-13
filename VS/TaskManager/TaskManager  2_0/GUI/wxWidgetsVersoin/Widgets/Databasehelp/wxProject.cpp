#include "../../Task Manager/Headers/DatabaseControl/Database.h"
std::deque <project> database::getProject() {
	std::deque<project> rPro;
	for (unsigned int i = 0; i < this->Dat.size(); i++) {
		rPro.push_back(rPro[i]);
	}
	return rPro;
}
