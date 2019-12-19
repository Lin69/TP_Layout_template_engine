#include <img.h>

block_model::Img::Img() : width_attr(0), height_attr(0) {

}

block_model::Img::Img(const block_model::Img& src) = default;

block_model::Img::Img(block_model::Img&& src) noexcept : Object(std::move(src)), width_attr(src.width_attr),
                                                         height_attr(src.height_attr), src_attr(std::move(src.src_attr)) {

}

block_model::Img& block_model::Img::operator=(const block_model::Img& src) {
    if (this == &src) {
        return *this;
    }

    CopyAttributes(src);
    width_attr = src.width_attr;
    height_attr = src.height_attr;
    src_attr.str = src.src_attr.str;
    return *this;
}

block_model::Img::~Img() = default;

void block_model::Img::SetSrc(const String& new_src) {
    src_attr.str = new_src.str;
}

void block_model::Img::SetWidth(const int& new_width) {
    width_attr = new_width;
}

void block_model::Img::SetHeight(const int &new_height) {
    height_attr = new_height;
}

void block_model::Img::SetTagContent(const block_model::String& new_content) {
    // Не делает ничего
}

block_model::String block_model::Img::MakeHtmlString() const {
    block_model::String result("<img src=\"");

    result + src_attr;
    result + block_model::String("\"");

    if (width_attr) {
        WrapAttribute(result, block_model::String("width"), width_attr);
    }

    if (height_attr) {
        WrapAttribute(result, block_model::String("height"), height_attr);
    }

    CheckAttributes(result);

    return result;
}


