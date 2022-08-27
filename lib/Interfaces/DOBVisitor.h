#pragma once
#include "Visitor.h"
#include <string>
#include "XMLobj.h"
#include "Sink.h"

using namespace std;
class DOBVisitor : public Visitor
{
private:
	std::string data;

	

	vector <XMLobj*> v_LogO;
	XMLobj* tempObj = new XMLobj; //����������-������
	pair<string, string> tempPair;
	Sink* sinkname;
	

public:
	
    XMLobj* StartObj =new XMLobj;
	DOBVisitor( Sink* sinkvar);
	~DOBVisitor();		

	XMLobj* getDataTree(){ return StartObj; }
	

	void onParseKey(std::string key, int deep) override;
	void onParseStr(std::string value, int deep) override;
	void onAtribute(std::string value, int deep) override;
	void onAtributeValue(std::string value, int deep) override;
	void onParseEndKey(std::string key, int deep) override;
	void gg()override;
	void onFinished() override;
};

