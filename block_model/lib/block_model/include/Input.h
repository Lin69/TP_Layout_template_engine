#ifndef TP_LAYOUT_TEMPLATE_ENGINE_INPUT_H
#define TP_LAYOUT_TEMPLATE_ENGINE_INPUT_H

#include "FormsRelated.h"

enum _type {button, checkbox, file_attr, hidden_attr, image, password, radio, reset_attr, submit, text_attr};

class Input : public FormsRelated {
public:
    Input();
    Input(const Input& src);
    Input(Input&& src) noexcept;
    Input& operator=(const Input& src);
    ~Input();

    std::string make_html_string() override;

    void set_type(const _type& type);
    void set_value(const std::string& new_value);

private:
    _type type_attr;
    std::string value_attr;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_INPUT_H
