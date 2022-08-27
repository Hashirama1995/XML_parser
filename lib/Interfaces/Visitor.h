#pragma once
#include <string>


class Visitor 
{
public:
	virtual void onParseKey(std::string key,int deep) = 0;
	virtual void onParseEndKey(std::string key,int deep) = 0;
	virtual void  onParseStr(std::string value,int deep) = 0;
	virtual void onAtribute(std::string value, int deep) = 0;
	virtual void onAtributeValue(std::string value, int deep) = 0;
	virtual void gg() = 0;
	virtual void onFinished() = 0;
	//virtual std::pair<std::string, int> onParseNumber(int startNumber) = 0;
};