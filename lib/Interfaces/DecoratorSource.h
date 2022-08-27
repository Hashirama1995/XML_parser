#ifndef DECORATOR_SOURCE_H
#define DECORATOR_SOURCE_H

#include "Source.h"

#include <spdlog/spdlog.h>

class DecoratorSource : public Source
{

protected:
    Source* source_;

public:

    DecoratorSource(Source* source) : source_(source) {}

    virtual void setSource(std::string& generalString) override
    {
        spdlog::info("Source start");
        return this->source_->setSource(generalString);
    }
    
};

#endif // DECORATOR_SOURCE_H