#ifndef TP_LAYOUT_TEMPLATE_ENGINE_FORMSRELATEDCREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_FORMSRELATEDCREATOR_H

#include "Creator.h"

class ButtonCreator : public Creator {
public:
    virtual std::shared_ptr<Object> create_object() override;
    ~ButtonCreator();
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_FORMSRELATEDCREATOR_H
