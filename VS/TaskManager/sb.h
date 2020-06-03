#pragma once
#include <iostream>
#include <fstream>
#include <string>
namespace sb {
	std::string readline(std::string filepath, int linenum = 0) {
		std::string lnStr;
		std::fstream inflie;
		inflie.open(filepath);
		for (int i = 0; i < linenum; i++) {
			std::getline(inflie, lnStr);
		}
		inflie.close();
		return lnStr;
	}
	void init(const char fileName[]) {
		std::ofstream ofs;
		ofs.open(fileName);
		ofs << "";
	}
	void writeLine(int lineNum, std::string text, const char fileName[]) {
	std::ofstream ofs;
		ofs.open(fileName, std::ofstream::out | std::ios::app);
		ofs <<text<<"\n";
		ofs.close();
	}
}