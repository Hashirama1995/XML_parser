#pragma once
#include"Source.h"
#include <iostream>

class StringSource : public Source
{
public:
	void setSource(std::string &data) override;
};

