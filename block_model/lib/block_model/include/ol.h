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

        [[nodiscard]] string MakeHtmlString() const override;

        void SetTagContent(const string &new_content) override;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_OL_H
