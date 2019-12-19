#ifndef TP_LAYOUT_TEMPLATE_ENGINE_SELECT_H
#define TP_LAYOUT_TEMPLATE_ENGINE_SELECT_H

#include "list.h"

namespace block_model {
    class Select : virtual public List, virtual public Object {
    public:
        Select();
        Select(const Select& src);
        Select(Select&& src) noexcept;
        Select& operator=(const Select& src);
        ~Select() override;

        [[nodiscard]] Map MakeHtmlString() const override;

        void SetMultiple(const bool& value = true);
        void SetSize(const int& new_size);
        void SetRequired(const bool& value = true);

        void SetTagContent(const String &new_content) override;

    private:
        bool multiple_attr;
        bool required_attr;
        int size_attr;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_SELECT_H
