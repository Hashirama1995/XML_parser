#pragma once
#include <string>
#include <vector>
#include "Visitor.h"
#include "Source.h"

class ParserIntf
{
public:
   virtual void parse(std::string& data, Visitor* visitor)=0;
};

