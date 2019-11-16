#ifndef TP_LAYOUT_TEMPLATE_ENGINE_INPUT_H
#define TP_LAYOUT_TEMPLATE_ENGINE_INPUT_H

#include "FormsRelated.h"

class Input : public FormsRelated {
public:
    Input();
    Input(const Input& src);
    Input(Input&& src) noexcept;
    Input& operator=(const Input& src);
    ~Input();

    std::string make_html_string() override;

    void set_type(const int& new_value);
    void set_value(const std::string& new_value);

private:
    enum _type {button, checkbox, _file, hidden, image, password, radio, _reset, submit, _text} type_attr;
    std::string value_attr;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_INPUT_H
