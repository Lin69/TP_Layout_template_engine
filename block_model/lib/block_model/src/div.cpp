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

block_model::String block_model::Div::MakeHtmlString() const {
    block_model::String result("<div");

    CheckAttributes(result);
    result + block_model::String("\n");

    for (const auto& it : objects_content) {
        if (it) {
            result + it->MakeHtmlString();
            result + block_model::String("\n");
        }
    }

    result + block_model::String("</div>");

    return result;
}
