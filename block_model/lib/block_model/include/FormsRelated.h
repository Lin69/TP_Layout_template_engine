#ifndef TP_LAYOUT_TEMPLATE_ENGINE_FORMSRELATED_H
#define TP_LAYOUT_TEMPLATE_ENGINE_FORMSRELATED_H

#include "Object.h"
#include "Form.h"

class FormsRelated : public Object {
public:
    void set_form_ptr(std::shared_ptr<Form> new_form_ptr);
protected:
    std::shared_ptr<Form> form_ptr;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_FORMSRELATED_H
