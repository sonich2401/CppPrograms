#include <iostream>
#include <deque>
#include <time.h>
#pragma warning(disable : 4996)
struct date { //TODO: Add clock time as well for testing purposes
	          //TODO: Implement month to be month++ instead of implementing it in other .cpp files everytime we call setDate()
	uint8_t dd;
	uint8_t mm;
	uint16_t yyyy;
	uint8_t min;
	uint8_t sec;
	uint8_t hr;
	void setDate(uint8_t _dd, uint8_t _mm, uint16_t _yyyy) {
		yyyy = _yyyy-100+2000;
		dd = _dd;
		mm = _mm;
	}
	void getTime() {
		std::cout << "\n\n" << unsigned int(hr) << ":" << unsigned int(min) << ":" << unsigned int(sec)<<"\n";
	}
	void update() {
	time_t theTime = time(NULL);
	struct tm* aTime = localtime(&theTime);
	dd = aTime->tm_mday;
	mm = aTime->tm_mon+1;
	yyyy = aTime->tm_year;
	hr = aTime->tm_hour;
	min = aTime->tm_min;
	sec = aTime->tm_sec;
	}

};
struct task {
	date created;
	date modified;
	std::string name;
	bool st;
	std::string discription;
};
struct region {
	std::deque<task> Dat;
	date created;
	date modified;
	std::string name;
	std::string discription;
	void init(std::string _name,std::string initDiscription) {
		name = _name;
		discription = initDiscription;
	}
};
//TODO: Either Implement a std::map or make the map system require less code/effort/complexity