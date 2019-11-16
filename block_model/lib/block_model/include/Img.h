#ifndef TP_LAYOUT_TEMPLATE_ENGINE_IMG_H
#define TP_LAYOUT_TEMPLATE_ENGINE_IMG_H

#include "Object.h"

class Img : public Object {
public:
    Img();
    Img(const Img& src);
    Img(Img&& src) noexcept;
    Img& operator=(const Img& src);
    ~Img();

    std::string make_html_string() override;

    void set_src(const std::string& new_src);
    void set_width(const int& new_width);
    void set_height(const int& new_height);

private:
    int width_attr;
    int height_attr;
    std::string src_attr;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_IMG_H
