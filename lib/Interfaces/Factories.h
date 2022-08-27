#ifndef FACTORIES_H
#define FACTORIES_H

#include "Parser.h"
#include "Visitor.h"
#include "Source.h"
#include "Sink.h"

Visitor* makeVisitor(const std::string& type, Sink* sinkvar);
ParserIntf* makeParser(const std::string& type, Source* source);
Source* makeSource(const std::string& type);
Sink* makeSink(const std::string& type);

#endif // FACTORIES_H