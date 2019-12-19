#include <a.h>

block_model::A::A() = default;

block_model::A::A(const block_model::A& src) = default;

block_model::A::A(block_model::A&& src) noexcept : Object(std::move(src)), href(std::move(src.href)) {

}

block_model::A& block_model::A::operator=(const block_model::A& src) {
    if (this == &src) {
        return *this;
    }

    CopyAttributes(src);
    href.str = src.href.str;

    return *this;
}

block_model::A::~A() = default;

void block_model::A::SetHref(const block_model::String& new_href) {
    href.str = new_href.str;
}

block_model::Map block_model::A::MakeHtmlString() const {
    Map result;

    result.set_tag(String("a"));
    result.set_end();
    CheckAttributes(result);

    result.insert(String("href"), href);

    return result;
}

