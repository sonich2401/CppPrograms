#include "../Database.h"

void database::addRegion(string projectName, string regionName, string regionDiscription)
{
	int i = Indexer(this, projectName);
    if(i>-1){
		region tmpreg;
		tmpreg.name = regionName;
		tmpreg.discription = regionDiscription;
		this->Dat[i].Dat.push_back(tmpreg);
	}
}
bool database::editRegion(string projectName, string region,string newRegionName, string newRegionDiscription) {
	int i[2];
	i[0]=this->Indexer(this, projectName);
	if (i[0] > -1) {
		i[1] = Indexer(&this->Dat[i[0]], region);
	}
	else { return 0; }
	if (i[1] > -1) {
		this->Dat[i[0]].Dat[i[1]].name = newRegionName;
		this->Dat[i[0]].Dat[i[1]].discription = newRegionDiscription;
		this->Dat[i[0]].Dat[i[1]].modified.update();
	}
	else {
		return 0;
	}
}
bool database::delRegion(string projectName, string regionName)
{
	int i = Indexer(this, projectName);
	if (i == -1) {
		return 0;
	}
	else {
		int i1 = Indexer(&this->Dat[i],regionName);
		if (i1 != -1) {
			Dat[i].Dat.erase(Dat[i].Dat.begin() + i1);
			return 1;
		}
		else { return 0; }
	}
}