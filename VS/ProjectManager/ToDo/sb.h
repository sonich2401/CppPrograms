#pragma once
#include <fstream>
#include <string>
namespace sb {
	void writeFile() {
		std::ofstream ofs;
		std::ifstream is;
		is.open("a.txt", std::ios::in | std::ios::binary);
		ofs.open("temp.bin", std::ofstream::out | std::ofstream::binary);
		char c;
		char fileBin[1024];
		for (int i = 1; i < 1024; i++) {
			fileBin[i] = 0;
		}
		is.read(fileBin, 512);

		ofs << fileBin;
		ofs.close();
		is.close();
	}
}