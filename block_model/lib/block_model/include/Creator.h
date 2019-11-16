#ifndef TP_LAYOUT_TEMPLATE_ENGINE_CREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_CREATOR_H

#include "Object.h"

class Creator {
public:
    virtual std::shared_ptr<Object> create_object() = 0;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_CREATOR_H
