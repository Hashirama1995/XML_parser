#include <iostream>
#include <fstream>
#include <string>
#include <spdlog/spdlog.h>

#include "StringSource.h"
#include "SteamSource.h"
#include"chVisitor.h"
#include "Parser.h"
#include "Visitor.h"
#include "DOBVisitor.h"
#include "StringSink.h"
#include "SteamSink.h"
#include "Factories.h"
#include "ParserIntf.h"

///U should put in SteamSource.cpp the path to your .xml file

void main()
{
    

    std::string sourceType = "";
    std::string visitorType = "";
    std::string parserType = "";
    std::string sinkType = "";

    std::cout << "Put 0 if you don't want log process" << std::endl << "Put 1 if you want log process" << std::endl;

    bool loggingOn = false;
    std::cin >> loggingOn;
    std::cin.ignore(256, '\n');

    if (loggingOn)
    {
        sourceType = "logger";
        visitorType = "logger";
        parserType = "logger";
        sinkType = "logger";
    }
    
     std::cout << "Put 0 if you want put string to parse" << std::endl << "Put 1 if you want read file to parse" << std::endl;    

    // true - string, false - file
    bool inputType = false;
    std::cin >> inputType;
    std::cin.ignore(256, '\n');

    if (inputType)
    {
        sourceType = sourceType + "file";
    }

    Source* source=makeSource(sourceType);

     std::cout << std::endl << "Put 0 if you want out parsed as string" << std::endl << "Put 1 if you want out parsed string as file" << std::endl;

    // true - string, false - file
    inputType = false;
    std::cin >> inputType;

    if (inputType)
    {
        sinkType = sinkType + "file";
    }
    else
    {
        sinkType=sinkType+"string";
    }

    Sink* sink = makeSink(sinkType);

    Visitor* visitor123 = makeVisitor(visitorType, sink);
    
    ParserIntf* prs = makeParser(parserType, source);
    
    std::string data;

    prs->parse(data,visitor123);

}