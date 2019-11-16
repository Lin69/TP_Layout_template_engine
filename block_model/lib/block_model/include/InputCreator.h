#ifndef TP_LAYOUT_TEMPLATE_ENGINE_INPUTCREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_INPUTCREATOR_H

#include "Creator.h"

class InputCreator : public Creator {
public:
    virtual std::shared_ptr<Object> create_object() override;
    ~InputCreator();
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_INPUTCREATOR_H
