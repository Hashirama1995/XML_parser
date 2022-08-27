#pragma once
#include "Sink.h"

class StringSink:public Sink
{
public:
     StringSink();
	 ~StringSink();
	void getDataFrom(XMLobj* objXML) override;
};

