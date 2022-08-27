#include "Factories.h"
#include "Parser.h"
#include "DOBVisitor.h"
#include "SteamSource.h"
#include "SteamSink.h"
#include "StringSource.h"
#include "StringSink.h"
#include "DecoratorVisitor.h"
#include "DecoratorSource.h"
#include "DecoratorSink.h"
#include "DecoratorParser.h"

Visitor* makeVisitor(const std::string& type, Sink* sink)
{
    if (type == "logger")
    {
        std::string temp;
        return new DecoratorVisitor(new DOBVisitor(sink));
    }
    return new DOBVisitor(sink);
}



ParserIntf* makeParser(const std::string& type, Source* source)
{
    if (type == "logger")
    {
        return new DecoratorParser(new Parser(source));
    }
    return new Parser(source);
}


Source* makeSource(const std::string& type)
{
    if (type == "loggerfile")
    {
        return new DecoratorSource(new SteamSource);
    }
    else if (type == "loggerstring")
    {
        return new DecoratorSource(new StringSource);
    }
    else if (type == "file")
    {
        return new SteamSource;
    }
    else if (type == "string")
    {
        return new StringSource;
    }
    return new StringSource;
}


Sink* makeSink(const std::string& type)
{
    if (type == "loggerfile")
    {
        return new DecoratorSink(new SteamSink);
    }
    else if (type == "loggerstring")
    {
        return new DecoratorSink(new StringSink);
    }
    else if (type == "file")
    {
        return new SteamSink;
    }
    else if (type == "string")
    {
        return new StringSink;
    }
    return new StringSink;
    
}