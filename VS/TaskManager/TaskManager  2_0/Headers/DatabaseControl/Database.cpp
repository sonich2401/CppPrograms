#include "Database.h"
#include <string>
#define incer ++curline
#define readl(x) sb::readline(x,incer)
#define wrLine(x,y) sb::appLine(x,y)
#define l_pro Dat.front()
#define l_reg Dat.front().Dat
#define l_tsk l_reg.front().Dat
void database::settime(date* p,string fn)
{
	p->dd = std::stoi(readl(fn));
	p->mm = std::stoi(readl(fn));
	p->yyyy = std::stoi(readl(fn));
	p->hr = std::stoi(readl(fn));
	p->mini = std::stoi(readl(fn));
	p->sec = std::stoi(readl(fn));
}
void settime1(date* p,string fn) {
	wrLine(std::to_string(p->dd),fn);
	wrLine(std::to_string(p->mm),fn);
	wrLine(std::to_string(p->yyyy),fn);
	wrLine(std::to_string(p->hr),fn);
	wrLine(std::to_string(p->mini),fn);
	wrLine(std::to_string(p->sec),fn);
}
void database::saveDatabase() {
	std::string saveFileName = sb::savefn("Save File", "Project Database Save", "pds");
	if (saveFileName != "NULL") {
		sb::init(saveFileName);
		wrLine(std::to_string(Dat.size()), saveFileName);
		for (unsigned int i = 0; i < Dat.size(); i++) {
			wrLine(l_pro.name, saveFileName);
			wrLine(l_pro.discription, saveFileName);
			settime1(&l_pro.created, saveFileName);
			settime1(&l_pro.modified, saveFileName);
			wrLine(std::to_string(l_reg.size()), saveFileName);
			for (unsigned int i1 = 0; i1 < l_reg.size(); i1++) {
				wrLine(l_reg.front().name, saveFileName);
				wrLine(l_reg.front().discription, saveFileName);
				settime1(&l_reg.front().created, saveFileName);
				settime1(&l_reg.front().modified, saveFileName);
				wrLine(std::to_string(l_tsk.size()), saveFileName);
				for (unsigned int i2 = 0; i2 < l_tsk.size(); i2++) {
					wrLine(l_tsk.front().name, saveFileName);
					wrLine(l_tsk.front().discription, saveFileName);
					settime1(&l_tsk.front().created, saveFileName);
					settime1(&l_tsk.front().modified, saveFileName);
					wrLine(std::to_string(int(l_tsk.front().state)), saveFileName);
					l_tsk.pop_front();
				}
				l_reg.pop_front();
			}
			Dat.pop_front();
		}
	}
}
void database::loadDatabase() {
	std::string saveFileName = sb::openfn("Load File", "Project Database Save", "pds");
	string fn = saveFileName;
	if (sb::readline(fn,1) != "") {
		int project_c = 0;
		totalProjects = std::stoi(readl(fn));
		for (unsigned int i1 = 0; i1 < totalProjects; i1++) {
			project tmpProject;
			tmpProject.name = readl(fn);
			tmpProject.discription = readl(fn);
			settime(&tmpProject.created,saveFileName);
			settime(&tmpProject.modified,saveFileName);
				unsigned int totalRegions = std::stoi(readl(fn));
				for (unsigned int i = 0; i < totalRegions; i++) {
					region tmpRegion;
					tmpRegion.name = readl(fn);
					tmpRegion.discription = readl(fn);
					settime(&tmpRegion.created,saveFileName);
					settime(&tmpRegion.modified,saveFileName);
					unsigned int totalTasks = std::stoi(readl(fn));
					for (unsigned int i2 = 0; i2 < totalTasks; i2++) {
						task tmpTask;
						tmpTask.name = readl(fn);
						tmpTask.discription = readl(fn);
						settime(&tmpTask.created,saveFileName);
						settime(&tmpTask.modified,saveFileName);
						tmpTask.state = std::stoi(readl(fn));
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




//void database::saveDatabase() {
//	std::string saveFileName = sb::savefn("Save File", "Project Database Save", "pds");
//	if (saveFileName != "NULL") {
//		sb::init(saveFileName);
//		unsigned int sizes[4] = { Dat.size(),l_reg.size(),l_tsk.size(),l_pro.Dat.size() };
//		wrLine(std::to_string(sizes[0]), saveFileName);
//		for (unsigned int i = 0; i < sizes[0]; i++) {
//			wrLine(l_pro.name, saveFileName);
//			wrLine(l_pro.discription, saveFileName);
//			settime1(&l_pro.created, saveFileName);
//			settime1(&l_pro.modified, saveFileName);
//			wrLine(std::to_string(sizes[1]), saveFileName);
//			for (unsigned int i1 = 0; i1 < sizes[1]; i1++) {
//				wrLine(l_reg.front().name, saveFileName);
//				wrLine(l_reg.front().discription, saveFileName);
//				settime1(&l_reg.front().created, saveFileName);
//				settime1(&l_reg.front().modified, saveFileName);
//				wrLine(std::to_string(sizes[2]), saveFileName);
//				for (unsigned int i2 = 0; i2 < sizes[2]; i2++) {
//					wrLine(l_tsk.front().name, saveFileName);
//					wrLine(l_tsk.front().discription, saveFileName);
//					settime1(&l_tsk.front().created, saveFileName);
//					settime1(&l_tsk.front().modified, saveFileName);
//					wrLine(std::to_string(int(l_tsk.front().state)), saveFileName);
//					l_tsk.pop_front();
//				}
//				l_reg.pop_front();
//			}
//			Dat.pop_front();
//		}
//	}
//}