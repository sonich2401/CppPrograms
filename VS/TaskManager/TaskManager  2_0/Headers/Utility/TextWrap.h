#pragma once
#include <deque>
#include <string>
using std::deque;
using std::string;

static inline deque<string> DirtyTextWrap(string Input, int AreaWidth) {
	deque<string> lines;
	deque<string>words;
	string tmpline = "";
	int lineLen = 0;
	int MaxChar = AreaWidth / 16;
	for (unsigned int i = 0; i < Input.size(); i++) {
		if (lineLen++ < MaxChar) {
			tmpline += Input[i];
		}
		else
		{
			words.push_back(tmpline);
			tmpline = "";
			lineLen = 0;
		}
	}
	if (""!= tmpline) {
		words.push_back(tmpline);
	}
	return words;
}
inline deque<string> TextWrap(string Input, int AreaWidth) {
	deque<string> lines;
	deque<string>words;
	string tmpline = "";
	int lineLen = 0;
	int MaxChar = AreaWidth / 8;
	for (unsigned int i = 0; i < Input.size(); i++) {
		if (Input[i] != ' ') {
			tmpline += Input[i];

		}
		else {
			words.push_back(tmpline);
			tmpline = "";
			if (words.back().size() >= MaxChar) {
				std::deque<std::string> tmp = DirtyTextWrap(words.back(), AreaWidth);
				for (unsigned int i1 = 0; i1 < tmp.size(); i1++) {
					words.push_back(tmp[i]);
				}
			}
		}
	}
	tmpline = "";
	for (unsigned int i = 0; i < words.size(); i++) {
		if (words[i].size() + lineLen > MaxChar) {
			tmpline += words[i];
			if (words[i].size() < MaxChar) {
				tmpline += " ";
			}
			lineLen = tmpline.size();
		}
		else {
			lines.push_back(tmpline);
			tmpline = "";
			lineLen = tmpline.size();
		}
	}
	return lines;
}