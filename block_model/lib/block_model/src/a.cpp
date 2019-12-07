#include <a.h>

block_model::A::A() = default;

block_model::A::A(const block_model::A& src) {
    tag_content.str = src.tag_content.str;
    class_attr.vec = src.class_attr.vec;
    hidden = src.hidden;
    title.str = src.title.str;

    href.str = src.href.str;
}

block_model::A::A(block_model::A&& src) noexcept {
    tag_content.str = std::move(src.tag_content.str);
    class_attr.vec = std::move(src.class_attr.vec);
    hidden = src.hidden;
    title.str = std::move(src.title.str);

    href.str = std::move(src.href.str);

    id_attr = ----id_count;
}

block_model::A& block_model::A::operator=(const block_model::A& src) {
    tag_content.str = src.tag_content.str;
    class_attr.vec = src.class_attr.vec;
    hidden = src.hidden;
    title.str = src.title.str;

    href.str = src.href.str;
    return *this;
}

block_model::A::~A() = default;

void block_model::A::SetHref(const block_model::string& new_href) {
    href.str = new_href.str;
}

block_model::string block_model::A::MakeHtmlString() const {
    block_model::string result("<a href=\"");

    result + href;
    result + block_model::string("\"");

    CheckAttributes(result);

    result + block_model::string("</a>");

    return result;
}

