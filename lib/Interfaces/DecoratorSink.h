#ifndef DECORATOR_SINK_H
#define DECORATOR_SINK_H

#include "Sink.h"

#include <spdlog/spdlog.h>

class DecoratorSink : public Sink
{

protected:
    Sink* sink_;

public:

    DecoratorSink(Sink* sink) : sink_(sink) {}

    virtual void getDataFrom(XMLobj*objXML) override
    {
        spdlog::info("Sink start");
        return this->sink_->getDataFrom(objXML);
    }
    
};

#endif // DECORATOR_SINK_H