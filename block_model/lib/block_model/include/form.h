#ifndef TP_LAYOUT_TEMPLATE_ENGINE_FORM_H
#define TP_LAYOUT_TEMPLATE_ENGINE_FORM_H

#include "container.h"

class Form : virtual public Container, virtual public Object {
public:
    Form();
    Form(const Form& src);
    Form(Form&& src) noexcept;
    Form& operator=(const Form& src);
    ~Form();

    std::string MakeHtmlString() override;

    void SetAction(const std::string& new_action);
    void SetHttpMethod(const bool& value);

private:
    std::string action_attr;
    bool http_method;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_FORM_H
