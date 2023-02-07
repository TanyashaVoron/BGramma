#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

class Dictionary {
public:
	void Create();
	void PrintDictionary();
private:
	string TakeOutWord(string s);
	void ChangingTheCase();
	string Find(string s, int& count);
	void AddCount(string s, int count);
	int FindAddWord(string s);
	void AddWord(string word, int count);
};