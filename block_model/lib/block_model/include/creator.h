#ifndef TP_LAYOUT_TEMPLATE_ENGINE_CREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_CREATOR_H

#include "object.h"

namespace block_model {
    template <typename T>
    static std::pair<std::shared_ptr<Object>, std::shared_ptr<T>> Create() {
        auto ptr = std::make_shared<T>();
        std::shared_ptr<Object> obj = ptr;
        return std::make_pair(obj, ptr);
    }
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_CREATOR_H
