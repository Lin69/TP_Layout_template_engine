#ifndef TP_LAYOUT_TEMPLATE_ENGINE_A_CREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_A_CREATOR_H

#include "creator.h"
#include "a.h"

namespace block_model {
    class ACreator : public Creator {
    public:
        std::shared_ptr<Object> Create() override;
        ~ACreator() override = default;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_A_CREATOR_H
