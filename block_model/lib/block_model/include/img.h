#ifndef TP_LAYOUT_TEMPLATE_ENGINE_IMG_H
#define TP_LAYOUT_TEMPLATE_ENGINE_IMG_H

#include "object.h"

namespace block_model {
    class Img : public Object {
    public:
        Img();
        Img(const Img& src);
        Img(Img&& src) noexcept;
        Img& operator=(const Img& src);
        ~Img() override;

        [[nodiscard]] Map MakeHtmlString() const override;

        void SetSrc(const String& new_src);
        void SetWidth(const int& new_width);
        void SetHeight(const int& new_height);
        void SetTagContent(const String &new_content) override;

    private:
        int width_attr{};
        int height_attr{};
        String src_attr;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_IMG_H
