#include "../Database.h"

void database::addProject(string projectName, string _discription)
{
	project tmppro;
	tmppro.name = projectName;
	tmppro.discription = _discription;
	if (tmppro.Dat.size() != 0) {
		tmppro.Dat.pop_back();
	}
	Dat.push_back(tmppro);
}
bool database::editProject(string projectName, string newProjectName, string newProjectDiscription) {
	int i = Indexer(this, projectName);
	if (i != -1) {
		Dat[i].name = newProjectName;
		Dat[i].discription = newProjectDiscription;
		Dat[i].modified.update();
	}else{
		return 0;
	}
}
bool database::delProject(string projectName)
{
	int i = Indexer(this, projectName);
	if (i == -1) {
		return 0;
	}
	else {
		Dat.erase(Dat.begin() + i);
		return 1;
	}
}