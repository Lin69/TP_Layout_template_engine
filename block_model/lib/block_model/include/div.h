#ifndef TP_LAYOUT_TEMPLATE_ENGINE_DIV_H
#define TP_LAYOUT_TEMPLATE_ENGINE_DIV_H

#include "container.h"

class Div : virtual public Container, virtual public Object {
public:
    Div();
    Div(const Div& src);
    Div(Div&& src) noexcept;
    Div& operator=(const Div& src);
    ~Div();

    std::string make_html_string() override;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_DIV_H
