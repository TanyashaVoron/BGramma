#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include "Dictionary.h"
using namespace std;

class BGramma {
public:
	void Create();
	void PrintBGramma();
	string PlusBGramma(string s);
private:
	void CreateFile();
	string TakeOutWord(string s);
	string Find(string s, int& count);
	void AddCount(string s, int count);
	int FindAddWord(string s);
	void AddWord(string word, int count);
};