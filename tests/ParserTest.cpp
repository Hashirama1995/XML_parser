#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Parser.h"

#include "ParserIntf.h"
#include "Visitor.h"
#include "Source.h"
#include "Sink.h"
#include "DecoratorVisitor.h"
#include "DecoratorSource.h"
#include "DecoratorSink.h"
#include "DecoratorParser.h"
#include "Factories.h"
#include "DOBVisitor.h"
#include <utility>
#include <iostream>
#include <fstream>
#include <string>
#include <memory>

class MockVisitor : public DOBVisitor
{
public:
    MockVisitor(Sink* sink);
    ~MockVisitor();

    MOCK_METHOD2(onParseKey, void (std::string key, int deep));
    MOCK_METHOD2(onParseStr, void (std::string value, int deep));
    MOCK_METHOD2(onAtribute, void (std::string value, int deep));
    MOCK_METHOD2(onAtributeValue, void (std::string value, int deep));
    MOCK_METHOD2(onParseEndKey, void (std::string key, int deep));
   // MOCK_METHOD0(gg, void ());
   // MOCK_METHOD0(onFinished, void ());
};

MockVisitor::MockVisitor(Sink* Sink) : DOBVisitor(Sink)
{
    
}

MockVisitor::~MockVisitor()
{
    
}

TEST(ParserTest, trueTest) {

    std::string sourceType = "";
    std::string visitorType = "";
    std::string parserType = "";
    std::string sinkType = "";

    sourceType = sourceType + "file";
  
    Source* currentSource = makeSource(sourceType);

    Sink* sink = makeSink(sinkType);

    std::string temp; 


    MockVisitor mockVisitor(sink);

    ParserIntf* prs = makeParser(parserType, currentSource);

    // For string --- <?xml_version="1.0"?><Root black="cocain"><biba><simba dead="in_fiml" gay="gay">aaaaaaa</simba><pimba>JIMBO!</pimba></biba><boba>kurrva</boba></Root>

    //EXPECT_CALL(mockVisitor, onParseKey).Times(11);
    EXPECT_CALL(mockVisitor, onParseStr).Times(3);
    EXPECT_CALL(mockVisitor, onAtribute).Times(3);

    prs->parse(temp,&mockVisitor);
}