#ifndef TP_LAYOUT_TEMPLATE_ENGINE_DIVCREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_DIVCREATOR_H

#include "Creator.h"

class DivCreator : public Creator {
public:
    virtual std::shared_ptr<Object> create_object() override;
    ~DivCreator();
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_DIVCREATOR_H
