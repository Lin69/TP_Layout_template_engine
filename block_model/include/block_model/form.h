#ifndef TP_LAYOUT_TEMPLATE_ENGINE_FORM_H
#define TP_LAYOUT_TEMPLATE_ENGINE_FORM_H

#include "container.h"
namespace block_model {
    class Form : virtual public Container, virtual public Object {
    public:
        Form();
        Form(const Form& src);
        Form(Form&& src) noexcept;
        Form& operator=(const Form& src);
        ~Form() override;

        [[nodiscard]] Map MakeHtmlString() const override;

        void SetAction(const String& new_action);
        void SetHttpMethod(bool value = true);

        void SetTagContent(const String& new_content) override;

    private:
        String action_attr;
        bool http_method{};
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_FORM_H
