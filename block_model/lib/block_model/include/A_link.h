#ifndef TP_LAYOUT_TEMPLATE_ENGINE_A_LINK_H
#define TP_LAYOUT_TEMPLATE_ENGINE_A_LINK_H

#include "Object.h"

class A_link : public Object {
public:
    A_link();
    A_link(const A_link& src);
    A_link(A_link&& src) noexcept;
    A_link& operator=(const A_link& src);
    ~A_link();

    std::string make_html_string() override;

    void set_href(const std::string& new_href);

private:
    std::string href;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_A_LINK_H
