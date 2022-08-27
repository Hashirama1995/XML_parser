#pragma once
#include "Source.h"
#include <iostream>
#include <fstream>

class SteamSource: public Source
{
public:
	void setSource(std::string &data) override;
};

