#include <div.h>

block_model::Div::Div() = default;

block_model::Div::Div(const block_model::Div& src) {
    tag_content.str = src.tag_content.str;
    class_attr.vec = src.class_attr.vec;
    hidden = src.hidden;
    title.str = src.title.str;

    objects_content = src.objects_content;
}

block_model::Div::Div(block_model::Div&& src) noexcept {
    tag_content.str = std::move(src.tag_content.str);
    class_attr.vec = std::move(src.class_attr.vec);
    hidden = src.hidden;
    title.str = std::move(src.title.str);

    objects_content = std::move(src.objects_content);

    id_attr = ----id_count;
}

block_model::Div& block_model::Div::operator=(const block_model::Div& src) {
    tag_content.str = src.tag_content.str;
    class_attr.vec = src.class_attr.vec;
    hidden = src.hidden;
    title.str = src.title.str;

    objects_content = src.objects_content;

    return *this;
}

block_model::Div::~Div() = default;

block_model::string block_model::Div::MakeHtmlString() const {
    block_model::string result("<div");

    CheckAttributes(result);
    result + block_model::string("\n");

    for (const auto& it : objects_content) {
        if (it) {
            result + it->MakeHtmlString();
            result + block_model::string("\n");
        }
    }

    result + block_model::string("</div>");

    return result;
}
