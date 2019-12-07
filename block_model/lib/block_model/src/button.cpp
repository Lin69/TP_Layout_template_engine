#include <button.h>

block_model::Button::Button() = default;


block_model::Button::Button(const block_model::Button& src) {
    tag_content.str = src.tag_content.str;
    class_attr.vec = src.class_attr.vec;
    hidden = src.hidden;
    title.str = src.title.str;

    form_ptr = src.form_ptr;
}

block_model::Button::Button(block_model::Button&& src) noexcept {
    tag_content.str = std::move(src.tag_content.str);
    class_attr.vec = std::move(src.class_attr.vec);
    hidden = src.hidden;
    title.str = std::move(src.title.str);

    form_ptr = std::move(src.form_ptr);

    id_attr = ----id_count;
}

block_model::Button& block_model::Button::operator=(const block_model::Button& src) {
    tag_content.str = src.tag_content.str;
    class_attr.vec = src.class_attr.vec;
    hidden = src.hidden;
    title.str = src.title.str;

    form_ptr = src.form_ptr;

    return *this;
}

block_model::Button::~Button() = default;

block_model::string block_model::Button::MakeHtmlString() const {
    block_model::string result("<button");

    if (form_ptr) {
        WrapAttribute(result, block_model::string("form"), form_ptr->GetId());
    }

    CheckAttributes(result);

    result + block_model::string("</button>");

    return result;
}
