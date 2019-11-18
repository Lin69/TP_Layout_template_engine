#ifndef TP_LAYOUT_TEMPLATE_ENGINE_FORMS_RELATED_H
#define TP_LAYOUT_TEMPLATE_ENGINE_FORMS_RELATED_H

#include "object.h"
#include "form.h"

class FormsRelated {
public:
    void set_form_ptr(std::shared_ptr<Form> new_form_ptr);
protected:
    std::shared_ptr<Form> form_ptr;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_FORMS_RELATED_H
