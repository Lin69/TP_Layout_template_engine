#ifndef TP_LAYOUT_TEMPLATE_ENGINE_A_H
#define TP_LAYOUT_TEMPLATE_ENGINE_A_H

#include "object.h"

namespace block_model {
    class A : public Object {
        public:
            A();
            A(const A& src);
            A(A&& src) noexcept;
            A& operator=(const A& src);
            ~A() override;

            [[nodiscard]] string MakeHtmlString() const override;

            void SetHref(const string& new_href);

        private:
            string href;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_A_H
