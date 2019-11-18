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

    std::string MakeHtmlString() override;
    void SetMultiple(const int& new_multiple);
    void SetSize(const int& new_size);
    void SetRequired(const bool& value);

private:
    int multiple_attr;
    bool required_attr;
    int size_attr;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_SELECT_H
