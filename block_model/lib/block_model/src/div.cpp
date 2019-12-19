#include <div.h>

block_model::Div::Div() = default;

block_model::Div::Div(const block_model::Div& src) = default;

block_model::Div::Div(block_model::Div&& src) noexcept : Object(std::move(src)) {
    objects_content = std::move(src.objects_content);
}

block_model::Div& block_model::Div::operator=(const block_model::Div& src) {
    if (this == &src) {
        return *this;
    }

    CopyAttributes(src);
    objects_content = src.objects_content;

    return *this;
}

block_model::Div::~Div() = default;

block_model::Map block_model::Div::MakeHtmlString() const {
    Map result;

    result.set_tag(String("div"));
    result.set_end();
    CheckAttributes(result);

    for (const auto& it : objects_content) {
            result.insert(String(object_template) + String(it->GetId()));
    }

    return result;
}
