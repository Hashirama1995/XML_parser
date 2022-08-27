#pragma once
#include "XMLobj.h"

class Sink
{
public:
	virtual void getDataFrom(XMLobj*objXML) = 0;
};
