#ifndef TP_LAYOUT_TEMPLATE_ENGINE_CREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_CREATOR_H

#include "object.h"

class Creator {
public:
    virtual std::shared_ptr<Object> CreateObject() = 0;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_CREATOR_H
