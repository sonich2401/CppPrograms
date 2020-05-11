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
	void writeLine(int lineNum, std::string text, const char fileName[]) {
		std::ofstream ofs;
		std::ifstream is(fileName);
		ofs.open("temp.txt", std::ofstream::out);
		char c;
		bool st = 1;
		int line_no = 1;
		while (is.get(c))
		{
			// if a newline character 
			if (c == '\n')
				line_no++;

			// file content not to be deleted 
			if (line_no != lineNum) {
				ofs << c;
			}
			if (line_no == lineNum && st == 1) { ofs << "\n" << text; st = 0; }

		}

		// closing output file 

		// remove the original file 
		remove(fileName);

		// rename the file 
		rename("temp.txt", fileName);
		ofs.close();
		is.close();
	}
}