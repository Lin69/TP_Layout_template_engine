#ifndef TP_LAYOUT_TEMPLATE_ENGINE_INPUT_H
#define TP_LAYOUT_TEMPLATE_ENGINE_INPUT_H

#include "forms_related.h"

namespace block_model {
    enum object_type {button, checkbox, file_attr, hidden_attr, image, password, radio, reset_attr, submit, text_attr};

    class Input : virtual public FormsRelated, virtual public Object {
    public:
        Input();
        Input(const Input& src);
        Input(Input&& src) noexcept;
        Input& operator=(const Input& src);
        ~Input() override;

        [[nodiscard]] string MakeHtmlString() const override;

        void SetType(const object_type& type);
        void SetValue(const string& new_value);

    private:
        object_type type_attr;
        string value_attr;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_INPUT_H
