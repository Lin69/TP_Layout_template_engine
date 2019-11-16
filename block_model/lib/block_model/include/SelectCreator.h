#ifndef TP_LAYOUT_TEMPLATE_ENGINE_SELECTCREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_SELECTCREATOR_H

#include "Creator.h"

class SelectCreator : public Creator {
public:
    virtual std::shared_ptr<Object> create_object() override;
    ~SelectCreator();
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_SELECTCREATOR_H
