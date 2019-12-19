#include <ol.h>

block_model::Ol::Ol() = default;

block_model::Ol::Ol(const block_model::Ol& src) = default;

block_model::Ol::Ol(block_model::Ol&& src) noexcept : Object(std::move(src)) {
    list_content.vec = std::move(src.list_content.vec);
}

block_model::Ol &block_model::Ol::operator=(const block_model::Ol &src) {
    if (this == &src) {
        return *this;
    }

    CopyAttributes(src);
    list_content.vec = src.list_content.vec;

    return *this;
}

block_model::Ol::~Ol() = default;

void block_model::Ol::SetTagContent(const block_model::String &new_content) {

}

block_model::String block_model::Ol::MakeHtmlString() const {
    block_model::String result("<ol");

    CheckAttributes(result);

    result + block_model::String("\n");

    for (const auto& it : list_content.vec) {
        result + block_model::String("\t<li>");
        result + it;
        result + block_model::String("</li>\n");
    }

    result + block_model::String("</ol>");

    return result;
}
