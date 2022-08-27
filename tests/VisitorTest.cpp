#include <gtest/gtest.h>
#include "DOBVisitor.h"

#include "ParserIntf.h"
#include "Visitor.h"
#include "Source.h"
#include "Sink.h"
#include "DecoratorVisitor.h"
#include "DecoratorSource.h"
#include "DecoratorSink.h"
#include "DecoratorParser.h"
#include "Factories.h"

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

TEST(VisitorTest, trueTest) {

    std::string sourceType = "";
    std::string visitorType = "";
    std::string parserType = "";
    std::string sinkType = "";

    sourceType = sourceType + "file";
  
    Source* currentSource = makeSource(sourceType);

    Sink* sink = makeSink(sinkType);

    DOBVisitor visitor(sink);

    std::string key = "key";
    std::string value = "value";

    visitor.onParseKey(key, 0);
    visitor.gg();
    visitor.onParseKey(key, 1);
    visitor.gg();
    
    
    
    
    /*key = key + "1";
    visitor.onParseKey(key, 1);
    visitor.onParseStr(value);
    visitor.onParseKey(key, 1);
    key = "key2";
    visitor.onParseKey(key, 2);
    visitor.onParseStr(value);
    visitor.onParseKey(key, 2);
    visitor.onParseStr(value);
    key = "key";
    
    visitor.onParseKey(key, 0);
    key = key + "1";
    visitor.onParseKey(key, 1);
    visitor.onParseStr(value);*/

    EXPECT_EQ(visitor.StartObj->Node.size(), 1);
   // EXPECT_EQ(visitor.yamlVec[0]->nestedObjs.size(), 2);
   // EXPECT_EQ(visitor.yamlVec[0]->nestedObjs[1]->nestedObjs.size(), 2);
    //EXPECT_EQ(visitor.yamlVec[1]->nestedObjs.size(), 1);
}