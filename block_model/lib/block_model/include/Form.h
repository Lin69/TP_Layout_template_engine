#ifndef TP_LAYOUT_TEMPLATE_ENGINE_FORM_H
#define TP_LAYOUT_TEMPLATE_ENGINE_FORM_H

#include "Container.h"

class Form : public Container {
public:
    Form();
    Form(const Form& src);
    Form(Form&& src) noexcept;
    Form& operator=(const Form& src);
    ~Form();

    std::string make_html_string() override;

    void set_action(const std::string& new_action);
    void set_http_method(const bool& value);

private:
    std::string action_attr;
    bool http_method;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_FORM_H
