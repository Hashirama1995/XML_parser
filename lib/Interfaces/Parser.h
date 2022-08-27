#pragma once
#include <string>
#include <vector>
#include "Visitor.h"
#include "Source.h"
#include "ParserIntf.h"

class Parser: public ParserIntf
{
public:
    Parser(Source* mysrc);
    ~Parser();
    
    Source* src;
    void parse(std::string& data, Visitor* visitor) override;
};

