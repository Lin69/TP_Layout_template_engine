#ifndef TP_LAYOUT_TEMPLATE_ENGINE_UL_H
#define TP_LAYOUT_TEMPLATE_ENGINE_UL_H

#include "list.h"

namespace block_model {
    class Ul : virtual public List, virtual public Object {
    public:
        Ul();
        Ul(const Ul& src);
        Ul(Ul&& src) noexcept;
        Ul& operator=(const Ul& src);
        ~Ul() override;

        [[nodiscard]] String MakeHtmlString() const override;

        void SetTagContent(const String &new_content) override;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_UL_H
