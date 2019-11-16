#ifndef TP_LAYOUT_TEMPLATE_ENGINE_UL_H
#define TP_LAYOUT_TEMPLATE_ENGINE_UL_H

#include "List.h"

class Ul : public List {
public:
    Ul();
    Ul(const Ul& src);
    Ul(Ul&& src) noexcept;
    Ul& operator=(const Ul& src);
    ~Ul();

    std::string make_html_string() override;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_UL_H
