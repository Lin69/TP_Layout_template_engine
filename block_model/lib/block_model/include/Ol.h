#ifndef TP_LAYOUT_TEMPLATE_ENGINE_OL_H
#define TP_LAYOUT_TEMPLATE_ENGINE_OL_H

#include "List.h"

class Ol : public List {
public:
    Ol();
    Ol(const Ol& src);
    Ol(Ol&& src) noexcept;
    Ol& operator=(const Ol& src);
    ~Ol();

    std::string make_html_string() override;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_OL_H
