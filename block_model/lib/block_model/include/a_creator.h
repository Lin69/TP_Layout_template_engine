#ifndef TP_LAYOUT_TEMPLATE_ENGINE_A_CREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_A_CREATOR_H

#include "creator.h"

class ACreator : public Creator {
public:
    virtual std::shared_ptr<Object> CreateObject() override;
    ~ACreator();
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_A_CREATOR_H
