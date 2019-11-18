#ifndef TP_LAYOUT_TEMPLATE_ENGINE_A_H
#define TP_LAYOUT_TEMPLATE_ENGINE_A_H

#include "object.h"

class A : public Object {
public:
    A();
    A(const A& src);
    A(A&& src) noexcept;
    A& operator=(const A& src);
    ~A();

    std::string make_html_string() override;

    void set_href(const std::string& new_href);

private:
    std::string href;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_A_H
