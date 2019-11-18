#ifndef TP_LAYOUT_TEMPLATE_ENGINE_INPUT_CREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_INPUT_CREATOR_H

#include "creator.h"

class InputCreator : public Creator {
public:
    virtual std::shared_ptr<Object> create_object() override;
    ~InputCreator();
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_INPUT_CREATOR_H
