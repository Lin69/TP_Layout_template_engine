#ifndef TP_LAYOUT_TEMPLATE_ENGINE_FORMSRELATEDCREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_FORMSRELATEDCREATOR_H

#include "creator.h"

class ButtonCreator : public Creator {
public:
    virtual std::shared_ptr<Object> CreateObject() override;
    ~ButtonCreator();
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_FORMSRELATEDCREATOR_H
