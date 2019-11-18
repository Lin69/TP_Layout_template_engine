#ifndef TP_LAYOUT_TEMPLATE_ENGINE_TEXTAREA_CREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_TEXTAREA_CREATOR_H

#include "creator.h"

class TextareaCreator : public Creator {
public:
    virtual std::shared_ptr<Object> CreateObject() override;
    ~TextareaCreator();
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_TEXTAREA_CREATOR_H
