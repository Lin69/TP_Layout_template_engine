#ifndef TP_LAYOUT_TEMPLATE_ENGINE_DIV_CREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_DIV_CREATOR_H

#include "creator.h"

class DivCreator : public Creator {
public:
    virtual std::shared_ptr<Object> CreateObject() override;
    ~DivCreator();
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_DIV_CREATOR_H
