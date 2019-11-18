#ifndef TP_LAYOUT_TEMPLATE_ENGINE_UL_CREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_UL_CREATOR_H

#include "creator.h"

class UlCreator : public Creator {
public:
    virtual std::shared_ptr<Object> create_object() override;
    ~UlCreator();
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_UL_CREATOR_H
