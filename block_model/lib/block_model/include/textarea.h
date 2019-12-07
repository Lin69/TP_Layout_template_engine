#ifndef TP_LAYOUT_TEMPLATE_ENGINE_TEXTAREA_H
#define TP_LAYOUT_TEMPLATE_ENGINE_TEXTAREA_H

#include "forms_related.h"

namespace block_model {
    class Textarea : virtual public FormsRelated, virtual public Object {
    public:
        Textarea();
        Textarea(const Textarea& src);
        Textarea(Textarea&& src) noexcept;
        Textarea& operator=(const Textarea& src);
        ~Textarea() override;

        [[nodiscard]] string MakeHtmlString() const override;

        void SetCols(const int& new_cols);
        void SetRows(const int& new_rows);
        void SetMaxlength(const int& new_maxlength);
        void SetPlaceholder(const string& new_placeholder);
        void SetReadonly(const bool& value = true);
        void SetRequired(const bool& value = true);

    private:
        int cols;
        int rows;
        int maxlength;
        string placeholder;
        bool readonly;
        bool required_attr;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_TEXTAREA_H
