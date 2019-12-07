#ifndef TP_LAYOUT_TEMPLATE_ENGINE_UL_CREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_UL_CREATOR_H

#include "creator.h"
#include "ul.h"

namespace block_model {
    class UlCreator : public Creator {
    public:
        std::shared_ptr<Object> Create() override;
        ~UlCreator() override = default;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_UL_CREATOR_H
