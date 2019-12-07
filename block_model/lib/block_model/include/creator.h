#ifndef TP_LAYOUT_TEMPLATE_ENGINE_CREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_CREATOR_H

#include "object.h"

namespace block_model {
    class Creator {
    public:
        virtual std::shared_ptr<Object> Create() = 0;
        virtual ~Creator() = default;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_CREATOR_H
