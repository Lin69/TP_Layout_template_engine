#ifndef TP_LAYOUT_TEMPLATE_ENGINE_TEXTAREACREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_TEXTAREACREATOR_H

#include "Creator.h"

class TextareaCreator : public Creator {
public:
    virtual std::shared_ptr<Object> create_object() override;
    ~TextareaCreator();
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_TEXTAREACREATOR_H
