#ifndef TP_LAYOUT_TEMPLATE_ENGINE_CONTAINERCREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_CONTAINERCREATOR_H

#include "Creator.h"

class FormCreator : public Creator {
public:
    virtual std::shared_ptr<Object> create_object() override;
    ~FormCreator();
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_CONTAINERCREATOR_H
