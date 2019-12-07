#include <select.h>

block_model::Select::Select() : multiple_attr(false), size_attr(0), required_attr(false) {

}

block_model::Select::Select(const block_model::Select& src) {
    tag_content.str = src.tag_content.str;
    class_attr.vec = src.class_attr.vec;
    hidden = src.hidden;
    title.str = src.title.str;

    list_content.vec = src.list_content.vec;
    multiple_attr = src.multiple_attr;
    size_attr = src.size_attr;
    required_attr = src.required_attr;
}

block_model::Select::Select(block_model::Select&& src) noexcept {
    tag_content.str = std::move(src.tag_content.str);
    class_attr.vec = std::move(src.class_attr.vec);
    hidden = src.hidden;
    title.str = std::move(src.title.str);

    list_content.vec = std::move(src.list_content.vec);
    multiple_attr = src.multiple_attr;
    size_attr = src.size_attr;
    required_attr = src.required_attr;

    id_attr = ----id_count;
}

block_model::Select &block_model::Select::operator=(const block_model::Select& src) {
    tag_content.str = src.tag_content.str;
    class_attr.vec = src.class_attr.vec;
    hidden = src.hidden;
    title.str = src.title.str;

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

void block_model::Select::SetTagContent(const block_model::string &new_content) {

}

block_model::string block_model::Select::MakeHtmlString() const {
    block_model::string result("<select");

    if (multiple_attr) {
        result + block_model::string(" multiple");
    }

    if (required_attr) {
        result + block_model::string(" required");
    }

    if (size_attr) {
        WrapAttribute(result, block_model::string("size"), size_attr);
    }

    CheckAttributes(result);

    result + block_model::string("\n");

    for (const auto& it : list_content.vec) {
        result + block_model::string("\t<option>");
        result + it;
        result + block_model::string("</option>\n");
    }

    result + block_model::string("</select>");

    return result;
}
