#ifndef TP_LAYOUT_TEMPLATE_ENGINE_SELECT_CREATOR_H
#define TP_LAYOUT_TEMPLATE_ENGINE_SELECT_CREATOR_H

#include "creator.h"

class SelectCreator : public Creator {
public:
    virtual std::shared_ptr<Object> create_object() override;
    ~SelectCreator();
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_SELECT_CREATOR_H
