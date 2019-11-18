#ifndef TP_LAYOUT_TEMPLATE_ENGINE_IMG_H
#define TP_LAYOUT_TEMPLATE_ENGINE_IMG_H

#include "object.h"

class Img : public Object {
public:
    Img();
    Img(const Img& src);
    Img(Img&& src) noexcept;
    Img& operator=(const Img& src);
    ~Img();

    std::string MakeHtmlString() override;

    void SetSrc(const std::string& new_src);
    void SetWidth(const int& new_width);
    void SetHeight(const int& new_height);

private:
    int width_attr;
    int height_attr;
    std::string src_attr;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_IMG_H
