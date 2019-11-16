#ifndef TP_LAYOUT_TEMPLATE_ENGINE_ACREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_ACREATOR_H

#include "Creator.h"

class ACreator : public Creator {
public:
    virtual std::shared_ptr<Object> create_object() override;
    ~ACreator();
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_ACREATOR_H
