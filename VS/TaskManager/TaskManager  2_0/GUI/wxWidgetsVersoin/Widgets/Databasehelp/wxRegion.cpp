#include "../../Task Manager/Headers/DatabaseControl/Database.h"
std::deque <region> database::getRegion(int ProjectId) {
	std::deque <region> rReg;
		for (unsigned int k = 0; k < this->Dat[ProjectId].Dat.size();k++) {
			rReg.push_back(this->Dat[ProjectId].Dat[k]);
		}
		return rReg;
}
