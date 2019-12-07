#ifndef TP_LAYOUT_TEMPLATE_ENGINE_SELECT_CREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_SELECT_CREATOR_H

#include "creator.h"
#include "select.h"

namespace block_model {
    class SelectCreator : public Creator {
    public:
        std::shared_ptr<Object> Create() override;
        ~SelectCreator() override = default;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_SELECT_CREATOR_H
