#ifndef TP_LAYOUT_TEMPLATE_ENGINE_IMGCREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_IMGCREATOR_H

#include "Creator.h"

class ImgCreator : public Creator {
public:
    virtual std::shared_ptr<Object> create_object() override;
    ~ImgCreator();
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_IMGCREATOR_H
