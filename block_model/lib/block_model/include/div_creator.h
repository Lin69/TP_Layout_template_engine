#ifndef TP_LAYOUT_TEMPLATE_ENGINE_DIV_CREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_DIV_CREATOR_H

#include "creator.h"
#include "div.h"

namespace block_model {
    class DivCreator : public Creator {
    public:
        std::shared_ptr<Object> Create() override;
        ~DivCreator() override = default;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_DIV_CREATOR_H
