#pragma once
#include <fstream>
#include <string>
#include <deque>
#include <windows.h>
#include <sstream>
#include <iostream>
namespace sb {
	inline std::string readline(std::string filepath, int linenum = 0) {
		std::string lnStr;
		std::fstream inflie;
		inflie.open(filepath);
		for (int i = 0; i < linenum; i++) {
			std::getline(inflie, lnStr);
		}
		inflie.close();
		return lnStr;
	}
	inline void init(std::string fileName) {
		std::ofstream ofs(fileName);
		ofs << "";
	}
	inline void appLine(std::string text, std::string FileName) {
		std::fstream ofs(FileName, std::ios::app | std::ios::out);
		ofs << text<<"\n";
		ofs.close();
	}
	inline void writeLine(int lineNum, std::string text, std::string fileName) {
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
	inline std::string openfn(std::string Title, std::string fileTypeFullName, std::string fileEx)
	{
		std::wstringstream cls;
		//cls << fileTypeFullName.c_str() << "(." << fileEx.c_str() << ")\0*." << fileEx.c_str();
		std::wstring src;
		std::wstring filetypes = L"Project Database Save (.pds)|\0*.pds\0";
		cls.clear();
		cls << Title.c_str();
		const std::wstring title = cls.str();
		std::wstring filename(MAX_PATH, L'\0');
		OPENFILENAMEW ofn = { };
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFilter = L"Project Database Save (.pds)\0*.pds\0";
		ofn.lpstrFile = &filename[0];
		ofn.nMaxFile = MAX_PATH;
		ofn.lpstrTitle = title.c_str();
		ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

		if (GetOpenFileNameW(&ofn))
		{
			src = filename;
			std::string str(src.begin(), src.end());
			return str;
		}
		return "NULL";
	}
	inline std::string savefn(std::string Title, std::string fileTypeFullName, std::string fileEx)
	{
		std::wstringstream cls;
		cls << fileTypeFullName.c_str() << "(." << fileEx.c_str() << ")\0*." << fileEx.c_str();
		std::wstring src;
		std::wstring filetypes = cls.str();
		cls.clear();
		cls << Title.c_str();
		const std::wstring title = cls.str();
		std::wstring filename(MAX_PATH, L'\0');
		OPENFILENAMEW ofn = { };
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFilter = L"Project Database Save (.pds)\0*.pds\0";
		ofn.lpstrFile = &filename[0];
		ofn.nMaxFile = MAX_PATH;
		ofn.lpstrTitle = title.c_str();
		ofn.Flags = OFN_DONTADDTORECENT | OFN_OVERWRITEPROMPT;
		if (GetSaveFileNameW(&ofn))
		{
			src = filename;
			std::string str(src.begin(), src.end());
			return str;
		}
		return "NULL";
	}
}
