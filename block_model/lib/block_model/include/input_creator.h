#ifndef TP_LAYOUT_TEMPLATE_ENGINE_INPUT_CREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_INPUT_CREATOR_H

#include "creator.h"
#include "input.h"

namespace block_model {
    class InputCreator : public Creator {
    public:
        std::shared_ptr<Object> Create() override;
        ~InputCreator() override = default;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_INPUT_CREATOR_H
