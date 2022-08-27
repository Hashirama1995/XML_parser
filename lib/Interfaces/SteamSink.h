#pragma once
#include "Sink.h"
class SteamSink: public Sink
{
public:

	SteamSink();
	void getDataFrom(XMLobj* objXML);
};

