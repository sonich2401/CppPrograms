#include "../Database.h"

void database::addTask(string projectName, string regionName, string taskName, string taskDiscription)
{
	task tmptsk;
	tmptsk.name = taskName;
	tmptsk.discription = taskDiscription;
	int i = Indexer(this, projectName);
	int i1 = Indexer(&this->Dat[i], regionName);
	Dat[i].Dat[i1].Dat.push_back(tmptsk);
}
bool database::editTask(string projectName, string regionName, string taskName, string newTaskName, string newTaskDiscription){
	int i = Indexer(this, projectName);
	int i1 = Indexer(&this->Dat[i], regionName);
	int i2 = Indexer(&this->Dat[i].Dat[i1], taskName);
	if (i > -1 && i1 > -1 && i2>-1) {
		Dat[i].Dat[i1].Dat[i2].name = newTaskName;
		Dat[i].Dat[i1].Dat[i2].discription = newTaskDiscription;
		Dat[i].Dat[i1].Dat[i2].modified.update();
		return 1;
	}
	else {
		return 0;
	}
}
bool database::delTask(string projectName, string regionName, string taskName)
{
	int i = Indexer(this, projectName);
	int i1 = Indexer(&this->Dat[i], regionName);
	int i2 = Indexer(&this->Dat[i].Dat[i1], taskName);
	if (i > -1 && i1 > -1&&i2>-1) {
		Dat[i].Dat[i1].Dat.erase(Dat[i].Dat[i1].Dat.begin() + i);
		return 1;
	}
	else {
		return 0;
	}
}

