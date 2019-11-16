#ifndef TP_LAYOUT_TEMPLATE_ENGINE_TEXTAREA_H
#define TP_LAYOUT_TEMPLATE_ENGINE_TEXTAREA_H

#include "FormsRelated.h"

class Textarea : public FormsRelated {
public:
    Textarea();
    Textarea(const Textarea& src);
    Textarea(Textarea&& src) noexcept;
    Textarea& operator=(const Textarea& src);
    ~Textarea();

    std::string make_html_string() override;

    void set_cols(const int& new_cols);
    void set_rows(const int& new_rows);
    void set_maxlength(const int& new_maxlength);
    void set_placeholder(const std::string& new_placeholder);
    void set_readonly(const bool& value);
    void set_required(const bool& value);

private:
    int cols;
    int rows;
    int maxlength;
    std::string placeholder;
    bool readonly;
    bool required_attr;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_TEXTAREA_H
