#pragma once
#include <fstream>
#include <string>
#include <deque>
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
	//bool lineReadable(std::string filepath) {
	//	if (sb::readline(filepath, 1) != "") {
	//		return true;
	//	}
	//	else
	//		return false;
	//}
	void init(string fileName) {
		std::ofstream ofs(fileName);
		ofs << "";
	}
	void appLine(std::string text, string FileName) {
		std::fstream ofs(FileName, std::ios::app | std::ios::out);
		ofs << text<<"\n";
		ofs.close();
	}
	void writeLine(int lineNum, std::string text, string fileName) {
		std::fstream infile(fileName, std::ios::in);
		std::string tmpstr;
		std::deque<std::string> strd;
		while(!infile.eof()){
			std::getline(infile, tmpstr);
			strd.push_back(tmpstr);
		}
		infile.close();
	std::ofstream ofs(fileName, std::ofstream::out);
	for (unsigned int i = 0; i < strd.size(); i++) {
		if (lineNum == i + 1) {
			ofs << text;
		}
		else {
			ofs << strd[i];
		}
		if (i + 1 != strd.size()) {
			ofs << "\n";
		}
		}
		ofs.close();
	}
}