#ifndef DECORATOR_VISITOR_H
#define DECORATOR_VISITOR_H

#include "XMLObj.h"
#include "Visitor.h"

#include <utility>
#include <string>
#include <spdlog/spdlog.h>

class DecoratorVisitor : public Visitor
{

protected:
    Visitor* visitor_;

public:

    DecoratorVisitor(Visitor* visitor) : visitor_(visitor) {}

    virtual void onParseKey(std::string key,int deep) override
    {
        // TODO: spdlog::info("onParseKey spdlog::info("onParseKey");");
        spdlog::info("onParseKey: " + key);
        return this->visitor_->onParseKey(key, deep);
    }

     virtual void onParseEndKey(std::string key,int deep) override
    {
        // TODO: spdlog::info("onParseKey spdlog::info("onParseKey");");
        spdlog::info("onParseEndKey: " + key);
        return this->visitor_->onParseKey(key, deep);
    }

    virtual void  onParseStr(std::string value,int deep) override
    {
        spdlog::info("onParseStr: " + value);
        return this->visitor_->onParseStr(value,deep);
    }

     virtual void onAtribute(std::string value, int deep) override
    {
        // TODO: spdlog::info("onParseKey spdlog::info("onParseKey");");
        spdlog::info("onParseAtribute: " + value);
        return this->visitor_->onParseKey(value, deep);
    }

    virtual void onAtributeValue(std::string value, int deep) override
    {
        // TODO: spdlog::info("onParseKey spdlog::info("onParseKey");");
        spdlog::info("onParseAtribute: " + value);
        return this->visitor_->onParseKey(value, deep);
    }

    virtual void gg() override
    {
        spdlog::info("gg()");
        return this->visitor_->gg();
    }

    virtual void onFinished() override
    {
        spdlog::info("onFinished()");
        return this->visitor_->onFinished();
    }

};

#endif // DECORATOR_VISITOR_H