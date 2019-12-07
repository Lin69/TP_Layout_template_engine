#ifndef TP_LAYOUT_TEMPLATE_ENGINE_TEXTAREA_CREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_TEXTAREA_CREATOR_H

#include "creator.h"
#include "textarea.h"

namespace block_model {
    class TextareaCreator : public Creator {
    public:
        std::shared_ptr<Object> Create() override;
        ~TextareaCreator() override = default;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_TEXTAREA_CREATOR_H
