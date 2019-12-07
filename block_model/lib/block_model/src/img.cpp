#include <img.h>

block_model::Img::Img() : width_attr(0), height_attr(0) {

}

block_model::Img::Img(const block_model::Img& src) {
    tag_content.str = src.tag_content.str;
    class_attr.vec = src.class_attr.vec;
    hidden = src.hidden;
    title.str = src.title.str;

    width_attr = src.width_attr;
    height_attr = src.height_attr;
    src_attr.str = src.src_attr.str;
}

block_model::Img::Img(block_model::Img&& src) noexcept {
    tag_content.str = std::move(src.tag_content.str);
    class_attr.vec = std::move(src.class_attr.vec);
    hidden = src.hidden;
    title.str = std::move(src.title.str);

    width_attr = src.width_attr;
    height_attr = src.height_attr;
    src_attr.str = std::move(src.src_attr.str);

    id_attr = ----id_count;
}

block_model::Img& block_model::Img::operator=(const block_model::Img& src) {
    tag_content.str = src.tag_content.str;
    class_attr.vec = src.class_attr.vec;
    hidden = src.hidden;
    title.str = src.title.str;

    width_attr = src.width_attr;
    height_attr = src.height_attr;
    src_attr.str = src.src_attr.str;
    return *this;
}

block_model::Img::~Img() = default;

void block_model::Img::SetSrc(const string& new_src) {
    src_attr.str = new_src.str;
}

void block_model::Img::SetWidth(const int& new_width) {
    width_attr = new_width;
}

void block_model::Img::SetHeight(const int &new_height) {
    height_attr = new_height;
}

void block_model::Img::SetTagContent(const block_model::string& new_content) {
    // Не делает ничего
}

block_model::string block_model::Img::MakeHtmlString() const {
    block_model::string result("<img src=\"");

    result + src_attr;
    result + block_model::string("\"");

    if (width_attr) {
        WrapAttribute(result, block_model::string("width"), width_attr);
    }

    if (height_attr) {
        WrapAttribute(result, block_model::string("height"), height_attr);
    }

    CheckAttributes(result);

    return result;
}


