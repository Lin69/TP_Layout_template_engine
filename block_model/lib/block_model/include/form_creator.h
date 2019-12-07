#ifndef TP_LAYOUT_TEMPLATE_ENGINE_CONTAINERCREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_CONTAINERCREATOR_H

#include "creator.h"
#include "form.h"

namespace block_model {
    class FormCreator : public Creator {
    public:
        std::shared_ptr<Object> Create() override;
        ~FormCreator() override = default;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_CONTAINERCREATOR_H
