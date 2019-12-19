#include <ul.h>

block_model::Ul::Ul() = default;

block_model::Ul::Ul(const block_model::Ul& src) = default;

block_model::Ul::Ul(block_model::Ul&& src) noexcept : Object(std::move(src)) {
    list_content.vec = std::move(src.list_content.vec);
}

block_model::Ul& block_model::Ul::operator=(const block_model::Ul& src) {
    if (this == &src) {
        return *this;
    }

    CopyAttributes(src);
    list_content.vec = src.list_content.vec;

    return *this;
}

block_model::Ul::~Ul() = default;

void block_model::Ul::SetTagContent(const block_model::String& new_content) {

}

block_model::String block_model::Ul::MakeHtmlString() const {
    block_model::String result("<ul");

    CheckAttributes(result);

    result + block_model::String("\n");

    for (const auto& it : list_content.vec) {
        result + block_model::String("\t<li>");
        result + it;
        result + block_model::String("</li>\n");
    }

    result + block_model::String("</ul>");

    return result;
}
