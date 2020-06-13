#include "Database.h"
#include "../Utility/sb.h"
#include <string>
#define RenIncer ++curline
#define RenReadL(x) sb::readline(x,RenIncer)
#define RenWriteLine(x,y) sb::appLine(x,y)
//TODO Delete these Macros below this TODO message
#define RenPro tmpdta.Dat.front()
#define RenReg tmpdta.Dat.front().Dat
#define RenTsk RenReg.front().Dat
void database::settime(date* p,string fn)
{
	p->dd = std::stoi(RenReadL(fn));
	p->mm = std::stoi(RenReadL(fn));
	p->yyyy = std::stoi(RenReadL(fn));
	p->hr = std::stoi(RenReadL(fn));
	p->min = std::stoi(RenReadL(fn));
	p->sec = std::stoi(RenReadL(fn));
}
void settime1(date* p,string fn) {
	RenWriteLine(std::to_string(p->dd),fn);
	RenWriteLine(std::to_string(p->mm),fn);
	RenWriteLine(std::to_string(p->yyyy),fn);
	RenWriteLine(std::to_string(p->hr),fn);
	RenWriteLine(std::to_string(p->min),fn);
	RenWriteLine(std::to_string(p->sec),fn);
}
void database::saveDatabase(string saveFileName) {
	database tmpdta=*this;
	sb::init(saveFileName);
		const unsigned int sizes[4] = { tmpdta.Dat.size(),RenReg.size(),RenTsk.size(),RenPro.Dat.size() };
		RenWriteLine(std::to_string(sizes[0]),saveFileName);
		for (unsigned int i = 0; i < sizes[0]; i++) {
			RenWriteLine(RenPro.name,saveFileName);
			RenWriteLine(RenPro.discription,saveFileName);
			settime1(&RenPro.created,saveFileName);
			settime1(&RenPro.modified,saveFileName);
			RenWriteLine(std::to_string(sizes[1]),saveFileName);
			for (unsigned int i1 = 0; i1 < sizes[1]; i1++) {
				RenWriteLine(RenReg.front().name,saveFileName);
				RenWriteLine(RenReg.front().discription,saveFileName);
				settime1(&RenReg.front().created,saveFileName);
				settime1(&RenReg.front().modified,saveFileName);
				RenWriteLine(std::to_string(sizes[2]),saveFileName);
				for (unsigned int i2 = 0; i2 < sizes[2]; i2++) {
					RenWriteLine(RenTsk.front().name,saveFileName);
					RenWriteLine(RenTsk.front().discription,saveFileName);
					settime1(&RenTsk.front().created,saveFileName);
					settime1(&RenTsk.front().modified,saveFileName);
					RenWriteLine(std::to_string(int(RenTsk.front().state)),saveFileName);
					RenTsk.pop_front();
				}
				RenReg.pop_front();
			}
			tmpdta.Dat.pop_front();
		}
}
void database::loadDatabase(string saveFileName) {
	string fn = saveFileName;
	Dat.clear();
	if (sb::readline(fn,1) != "") {
		int project_c = 0;
		totalProjects = std::stoi(RenReadL(fn));
		for (unsigned int i1 = 0; i1 < totalProjects; i1++) {
			project tmpProject;
			tmpProject.name = RenReadL(fn);
			tmpProject.discription = RenReadL(fn);
			settime(&tmpProject.created,saveFileName);
			settime(&tmpProject.modified,saveFileName);
				unsigned int totalRegions = std::stoi(RenReadL(fn));
				for (unsigned int i = 0; i < totalRegions; i++) {
					region tmpRegion;
					tmpRegion.name = RenReadL(fn);
					tmpRegion.discription = RenReadL(fn);
					settime(&tmpRegion.created,saveFileName);
					settime(&tmpRegion.modified,saveFileName);
					unsigned int totalTasks = std::stoi(RenReadL(fn));
					for (unsigned int i2 = 0; i2 < totalTasks; i2++) {
						task tmpTask;
						tmpTask.name = RenReadL(fn);
						tmpTask.discription = RenReadL(fn);
						settime(&tmpTask.created,saveFileName);
						settime(&tmpTask.modified,saveFileName);
						tmpTask.state = std::stoi(RenReadL(fn));
						tmpRegion.Dat.push_back(tmpTask);
					}
					tmpProject.Dat.push_back(tmpRegion);
				}
				Dat.push_back(tmpProject);
			}
			curline = 0;
		}
}
database::database() {
}