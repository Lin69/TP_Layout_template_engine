#include <select.h>

block_model::Select::Select() : multiple_attr(false), size_attr(0), required_attr(false) {

}

block_model::Select::Select(const block_model::Select& src) = default;

block_model::Select::Select(block_model::Select&& src) noexcept : Object(std::move(src)),
                                                                  multiple_attr(src.multiple_attr),
                                                                  size_attr(src.size_attr),
                                                                  required_attr(src.required_attr) {
    list_content.vec = std::move(src.list_content.vec);
}

block_model::Select &block_model::Select::operator=(const block_model::Select& src) {
    if (this == &src) {
        return *this;
    }

    CopyAttributes(src);
    list_content.vec = src.list_content.vec;
    multiple_attr = src.multiple_attr;
    size_attr = src.size_attr;
    required_attr = src.required_attr;

    return *this;
}

block_model::Select::~Select() = default;

void block_model::Select::SetMultiple(const bool& value) {
    multiple_attr = value;
}

void block_model::Select::SetSize(const int& new_size) {
    size_attr = new_size;
}

void block_model::Select::SetRequired(const bool& value) {
    required_attr = value;
}

void block_model::Select::SetTagContent(const block_model::String &new_content) {

}

block_model::Map block_model::Select::MakeHtmlString() const {
    Map result;

    result.set_tag(String("select"));
    result.set_end();
    CheckAttributes(result);

    result.insert(String("multiple"), String(""));
    result.insert(String("required"), String(""));

    if (size_attr) {
        result.insert(String("size"), String(size_attr));
    }

    String list("\n");
    for (const auto& it : list_content.vec) {
        list + String("\t<option>") + it + String("</option>\n");
    }
    result.insert(list);

    return result;
}
