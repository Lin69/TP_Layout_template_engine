#ifndef TP_LAYOUT_TEMPLATE_ENGINE_DIV_H
#define TP_LAYOUT_TEMPLATE_ENGINE_DIV_H

#include "container.h"

namespace block_model {
    class Div : virtual public Container, virtual public Object {
    public:
        Div();
        Div(const Div& src);
        Div(Div&& src) noexcept;
        Div& operator=(const Div& src);
        ~Div() override;

        [[nodiscard]] string MakeHtmlString() const override;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_DIV_H
