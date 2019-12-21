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

block_model::Map block_model::Ol::MakeHtmlString() const {
    Map result;

    result.set_tag(String("ol"));
    result.set_end();
    CheckAttributes(result);

    String list("\n");
    for (const auto& it : list_content.vec) {
        list + String("\t<li>") + it + String("</ol>\n");
    }
    result.insert(list);

    return result;
}
