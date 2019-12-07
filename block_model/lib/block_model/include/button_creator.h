#ifndef TP_LAYOUT_TEMPLATE_ENGINE_FORMSRELATEDCREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_FORMSRELATEDCREATOR_H

#include "creator.h"
#include "button.h"

namespace block_model {
    class ButtonCreator : public Creator {
    public:
        std::shared_ptr<Object> Create() override;
        ~ButtonCreator() override = default;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_FORMSRELATEDCREATOR_H
