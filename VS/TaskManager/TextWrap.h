#pragma once
#include <deque>
#include <string>
#include <iostream>
using std::string;
using std::deque;
using std::cout;
deque<string> textwrap(unsigned int x,unsigned int y,unsigned int width,unsigned int height,string Text) {
	deque<string> line;
	deque<string> words;
	string tmpline="";
	unsigned int maxX = width / 8;
	unsigned int linelen = 0;
	Text += ' ';
	for (unsigned int i = 0; i < Text.size(); i++) {
		if (Text[i] !=' ') {
			tmpline += Text[i];
		}
		else {
			words.push_back(tmpline);
			tmpline = "";
		}
	}
	tmpline = "";
	for (unsigned int i = 0; i < words.size(); i++) {
		if (words[i].size() + linelen + 1 < maxX) {
			for (unsigned int i1 = 0; i1 < words[i].size(); i1++) {
				tmpline += words[i][i1];
			}
			tmpline += ' ';
			linelen=tmpline.size();
		}
		else {
			//cout << tmpline<<"\n";
			line.push_back(tmpline);
			tmpline = "";
			if (words[i].size()+ linelen+ 1 > maxX) {
				for (unsigned int i1 = 0; i1 < words[i].size(); i1++) {
					tmpline += words[i][i1];
				}
				tmpline += " ";
				linelen = tmpline.size();
			}
			else { linelen = 0; }
		}
		/*if (words[i].size() + 1 > maxX) {             //IF STRING IS TOO BIG TURN IT INTO TWO WORDS
			tmpline = "";
			for (unsigned int i2 = i; i2 < words.size(); i2++) {
				for (unsigned int i3 = 0; i3 < words[i].size() - (words[i].size() - maxX); i3++) {
					tmpline += words[i3];
				}
				for (unsigned int i3 = words[i].size() - (words[i].size() - maxX; i3 < words[i].size()) {
					
				}
			}
		}*/  
	}
	line.push_back(words.back());
	return line;
}
deque<string> simpTextWrap(unsigned int width, string text, int charlen = 8) {
	deque<string> line;
	string tmpline = "";
	int linelen=0;
	for (unsigned int i = 0; i < text.size(); i++) {
		if (line.size() >= 3) {
			string tmpstr = line.back();
			tmpstr += '.';
			tmpstr += '.';
			tmpstr += '.';
			line.pop_back();
			line.push_back(tmpstr);
		}
		else {
			tmpline += text[i];
			if (++linelen > charlen || linelen == text.size()) {
				linelen = 0;
				line.push_back(tmpline);
				tmpline = "";
			}
		}
	}
	return line;
}