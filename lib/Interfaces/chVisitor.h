#pragma once
#include "Visitor.h"
#include <string>


class chVisitor : public Visitor
{
private:
	std::string data;
public:
	chVisitor(std::string& data);
	~chVisitor();

	//std::string data;
	
	virtual void onParseKey(std::string key, int deep) override;
	virtual void onParseStr(std::string value, int deep) override;
	virtual void onAtribute(std::string value, int deep) override;
	virtual void onAtributeValue(std::string value, int deep) override;
	virtual void onParseEndKey(std::string key, int deep) override;
	virtual void gg()override;
	virtual void onFinished() override;
};

