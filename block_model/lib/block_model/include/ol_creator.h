#ifndef TP_LAYOUT_TEMPLATE_ENGINE_OL_CREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_OL_CREATOR_H

#include "creator.h"

class OlCreator : public Creator {
public:
    virtual std::shared_ptr<Object> CreateObject() override;
    ~OlCreator();
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_OL_CREATOR_H
