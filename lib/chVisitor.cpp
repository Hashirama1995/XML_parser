#include "chVisitor.h"
#include <string>
#include <iostream>

chVisitor::chVisitor(std::string& data)
{
	this->data = data;
}

chVisitor::~chVisitor()
{
}

void chVisitor::onParseKey(std::string key, int deep)
{
	std::cout << std::endl;
	for (int i = 0; i < deep; i++)
	{
		std::cout << " ";
	}
	std::cout << "<" << key << ">";
}

void chVisitor::onParseEndKey(std::string endkey, int deep)
{
	std::cout << std::endl;
	for (int i = 0; i < deep; i++)
	{
		std::cout << " ";
	}
	std::cout <<"<" << endkey <<">";
}

void chVisitor::gg()
{
}

void chVisitor::onFinished()
{
}

void chVisitor::onParseStr(std::string value, int deep)
{
	std::cout << std::endl;
	for (int i = 0; i < deep; i++)
	{
		std::cout << " ";
	}
	std::cout << value;
}

void chVisitor::onAtribute(std::string value, int deep)
{
	
	std::cout <<"( " << value << "=";
}

void chVisitor::onAtributeValue(std::string value, int deep)
{
	std::cout << value<<" )";
}



