#ifndef TP_LAYOUT_TEMPLATE_ENGINE_OL_H
#define TP_LAYOUT_TEMPLATE_ENGINE_OL_H

#include "list.h"

namespace block_model {
    class Ol : virtual public List, virtual public Object {
    public:
        Ol();
        Ol(const Ol& src);
        Ol(Ol&& src) noexcept;
        Ol& operator=(const Ol& src);
        ~Ol();

        [[nodiscard]] Map MakeHtmlString() const override;

        void SetTagContent(const String &new_content) override;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_OL_H
