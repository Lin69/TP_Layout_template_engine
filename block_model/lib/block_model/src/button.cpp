#include <button.h>

block_model::Button::Button() = default;


block_model::Button::Button(const block_model::Button& src) = default;

block_model::Button::Button(block_model::Button&& src) noexcept : Object(std::move(src)) {
    form_ptr = std::move(src.form_ptr);
}

block_model::Button& block_model::Button::operator=(const block_model::Button& src) {
    if (this == &src) {
        return *this;
    }

    CopyAttributes(src);
    form_ptr = src.form_ptr;

    return *this;
}

block_model::Button::~Button() = default;

block_model::String block_model::Button::MakeHtmlString() const {
    block_model::String result("<button");

    if (form_ptr) {
        WrapAttribute(result, block_model::String("form"), form_ptr->GetId());
    }

    CheckAttributes(result);

    result + block_model::String("</button>");

    return result;
}
