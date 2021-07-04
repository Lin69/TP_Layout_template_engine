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

block_model::Map block_model::Button::MakeHtmlString() const {
    Map result;

    result.set_tag(String("button"));
    result.set_end();
    CheckAttributes(result);

    if (form_ptr) {
        result.insert(String("form"), String(form_ptr->GetId()));
    }

    return result;
}
