#ifndef TP_LAYOUT_TEMPLATE_ENGINE_IMG_CREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_IMG_CREATOR_H

#include "creator.h"
#include "img.h"

namespace block_model {
    class ImgCreator : public Creator {
    public:
        std::shared_ptr<Object> Create() override;
        ~ImgCreator() override = default;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_IMG_CREATOR_H
