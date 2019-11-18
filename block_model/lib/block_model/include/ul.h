#ifndef TP_LAYOUT_TEMPLATE_ENGINE_UL_H
#define TP_LAYOUT_TEMPLATE_ENGINE_UL_H

#include "list.h"

class Ul : virtual public List, virtual public Object {
public:
    Ul();
    Ul(const Ul& src);
    Ul(Ul&& src) noexcept;
    Ul& operator=(const Ul& src);
    ~Ul();

    std::string MakeHtmlString() override;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_UL_H
