#include "../../Task Manager/Headers/DatabaseControl/Database.h"
std::deque <task> database::getTask(int ProjectId,int RegionId) {
	std::deque<task> rTsk;
	for (unsigned int i = 0; i < this->Dat[ProjectId].Dat[RegionId].Dat.size(); i++) {
		rTsk.push_back(this->Dat[ProjectId].Dat[RegionId].Dat[i]);
	}
	return rTsk;
}
