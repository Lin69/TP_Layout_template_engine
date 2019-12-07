#ifndef TP_LAYOUT_TEMPLATE_ENGINE_OL_CREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_OL_CREATOR_H

#include "creator.h"
#include "ol.h"

namespace block_model {
    class OlCreator : public Creator {
    public:
        std::shared_ptr<Object> Create() override;
        ~OlCreator() override = default;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_OL_CREATOR_H
