#pragma once
#include <time.h>
#include <iostream>
#pragma warning(disable : 4996)
struct date {
	int dd;
	int mm;
	int yyyy;
	int min;
	int sec;
	int hr;
	void getTime() {
		std::cout << "\n\n" << unsigned int(hr) << ":" << unsigned int(min) << ":" << unsigned int(sec) << "\n";
	}
	void update() {
		time_t theTime = time(NULL);
		struct tm* aTime = localtime(&theTime);
		dd = aTime->tm_mday;
		mm = aTime->tm_mon + 1;
		yyyy = aTime->tm_year;
		hr = aTime->tm_hour;
		min = aTime->tm_min;
		sec = aTime->tm_sec;
	}
};