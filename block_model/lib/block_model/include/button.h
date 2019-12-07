#ifndef TP_LAYOUT_TEMPLATE_ENGINE_BUTTON_H
#define TP_LAYOUT_TEMPLATE_ENGINE_BUTTON_H

#include "forms_related.h"

namespace block_model {
    class Button : virtual public FormsRelated, virtual public Object {
    public:
        Button();
        Button(const Button& src);
        Button(Button&& src) noexcept;
        Button& operator=(const Button& src);
        ~Button() override;

        [[nodiscard]] string MakeHtmlString() const override;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_BUTTON_H
