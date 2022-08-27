#ifndef DECORATOR_PARSER_H
#define DECORATOR_PARSER_H

#include "ParserIntf.h"

#include <spdlog/spdlog.h>

class DecoratorParser : public ParserIntf
{

protected:
    ParserIntf* parser_;

public:

    DecoratorParser(ParserIntf* parser) : parser_(parser) {}

    virtual void parse(std::string& data2, Visitor* visitor) override
    {
        spdlog::info("Parser start");
        
        return this->parser_->parse(data2, visitor);
    }
    
};

#endif // DECORATOR_PARSER_H