#ifndef TP_LAYOUT_TEMPLATE_ENGINE_SELECT_H
#define TP_LAYOUT_TEMPLATE_ENGINE_SELECT_H

#include "list.h"

class Select : virtual public List, virtual public Object {
public:
    Select();
    Select(const Select& src);
    Select(Select&& src) noexcept;
    Select& operator=(const Select& src);
    ~Select();

    std::string make_html_string() override;
    void set_multiple(const int& new_multiple);
    void set_size(const int& new_size);
    void set_required(const bool& value);

private:
    int multiple_attr;
    bool required_attr;
    int size_attr;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_SELECT_H
