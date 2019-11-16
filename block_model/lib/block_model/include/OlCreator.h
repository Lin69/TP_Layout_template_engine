#ifndef TP_LAYOUT_TEMPLATE_ENGINE_OLCREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_OLCREATOR_H

#include "Creator.h"

class OlCreator : public Creator {
public:
    virtual std::shared_ptr<Object> create_object() override;
    ~OlCreator();
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_OLCREATOR_H
