#include "DOBVisitor.h"
#include "XMLobj.h"



using namespace std;
DOBVisitor::DOBVisitor( Sink* sinkvar) 
{
	
	this->sinkname = sinkvar;
}

DOBVisitor::~DOBVisitor()
{
}



void DOBVisitor::gg()
{
	

	if (tempObj->deep == 0)
	{
		v_LogO.insert(v_LogO.begin(), tempObj);
		StartObj = tempObj;
	}
	if (tempObj->deep > 0)
	{
		for (auto a : v_LogO)
		{
			if (a->deep == (tempObj->deep - 1))
			{
		
				a->Node.push_back(tempObj);
				v_LogO.insert(v_LogO.begin(), tempObj);
				break;
			}
		}
	}

	tempObj = new XMLobj;
}



void DOBVisitor::onParseKey(std::string key, int deep)
{
	XMLobj* baseObj = new XMLobj;// �������� ������ �� ����� ����
	tempObj = baseObj;
	tempObj->key = key;
	tempObj->deep = deep;
}

void DOBVisitor::onParseStr(std::string value, int deep)
{
	tempObj->value.push_back(value);
}

void DOBVisitor::onAtribute(std::string value, int deep)
{
	tempPair = { "","" };//������� ���������� ���� ������
	tempPair.first = value;// ������� �������
}

void DOBVisitor::onAtributeValue(std::string value, int deep)
{
	tempPair.second = value;//������� ��� ��������
	tempObj->atributs.push_back(tempPair);// ������� ���������� ���� � ���������� ������, � ������
}

void DOBVisitor::onParseEndKey(std::string key, int deep)
{
	tempObj->typeXML = key;
	tempObj->deep=0;
	//StartObj = tempObj;
//	v_LogO.insert(v_LogO.begin(), tempObj);
}


void DOBVisitor::onFinished()
{
	sinkname->getDataFrom(StartObj);
}