#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class XMLobj
{
private:
	string stroka;
public:
	XMLobj();
	~XMLobj();

	string typeXML;
	string key;
	vector<string> value;
	vector<pair<string, string>> atributs;
	void getData();
	string getDataFromSting(string cool);

	
	vector <XMLobj*> Node;

	int deep;
};

