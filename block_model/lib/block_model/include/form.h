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

        [[nodiscard]] string MakeHtmlString() const override;

        void SetAction(const string& new_action);
        void SetHttpMethod(const bool& value = true);

        int GetId() const;

        void SetTagContent(const string& new_content) override;

    private:
        string action_attr;
        bool http_method;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_FORM_H
