#ifndef TP_LAYOUT_TEMPLATE_ENGINE_FORMS_RELATED_H
#define TP_LAYOUT_TEMPLATE_ENGINE_FORMS_RELATED_H

#include "object.h"
#include "form.h"

namespace block_model {
    class FormsRelated {
    public:
        void SetFormPtr(std::shared_ptr<Form> new_form_ptr);

        virtual ~FormsRelated();

    protected:
        std::shared_ptr<Form> form_ptr;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_FORMS_RELATED_H
