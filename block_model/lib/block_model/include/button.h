#ifndef TP_LAYOUT_TEMPLATE_ENGINE_BUTTON_H
#define TP_LAYOUT_TEMPLATE_ENGINE_BUTTON_H

#include "forms_related.h"

class Button : public FormsRelated, public Object {
public:
    Button();
    Button(const Button& src);
    Button(Button&& src) noexcept;
    Button& operator=(const Button& src);
    ~Button();

    std::string make_html_string() override;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_BUTTON_H
