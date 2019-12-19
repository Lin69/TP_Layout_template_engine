#include <object.h>

block_model::Object::Object() : id_attr(id_count++), hidden(false) {

}

block_model::Object::Object(const block_model::Object& src) : id_attr(id_count++), tag_content(src.tag_content),
                                                              class_attr(src.class_attr), hidden(src.hidden),
                                                              title(src.title) {

}

block_model::Object::Object(block_model::Object&& src) noexcept : id_attr(src.id_attr),
                                                                  tag_content(std::move(src.tag_content)),
                                                                  class_attr(std::move(src.class_attr)),
                                                                  hidden(src.hidden),
                                                                  title(std::move(src.title)) {

}

block_model::Object::~Object() = default;

void block_model::Object::SetTagContent(const block_model::String& new_content) {
    tag_content.str = new_content.str;
}

void block_model::Object::SetClass(const block_model::String& new_class) {
    class_attr.vec.clear();
    class_attr.vec.push_back(new_class);
}

void block_model::Object::SetClass(const block_model::vector<block_model::String>& new_class) {
    class_attr.vec = new_class.vec;
}

void block_model::Object::SetHidden(const bool& value = true) {
    hidden = value;
}

void block_model::Object::SetTitle(const block_model::String& new_title) {
    title.str = new_title.str;
}

void block_model::Object::CheckAttributes(block_model::String& result) const {
    result + block_model::String(" id=\"");
    result + block_model::String(id_attr);
    result + block_model::String("\"");

    if (!class_attr.is_empty()) {
        result + block_model::String(" class=\"");
        for (const auto& it : class_attr.vec) {
            result + it;

            if (it.str != class_attr.vec.back().str) {
                result + block_model::String(" ");
            }
        }
        result + block_model::String("\"");
    }

    if (hidden) {
        result + block_model::String(" hidden");
    }

    if (!title.is_empty()) {
        result + block_model::String(" title=\"");
        result + title;
        result + block_model::String("\"");
    }

    result + block_model::String(">");
    result + tag_content;
}

int block_model::Object::id_count = 0;

void block_model::Object::WrapAttribute(block_model::String& result, const block_model::String& attribute,
                                        const block_model::String& value) const {
    result + block_model::String(" ");
    result + attribute;
    result + block_model::String("=\"");
    result + value;
    result + block_model::String("\"");
}

void block_model::Object::WrapAttribute(block_model::String& result, const block_model::String& attribute,
                                        const int& value) const {
    result + block_model::String(" ");
    result + attribute;
    result + block_model::String("=\"");
    result + block_model::String(value);
    result + block_model::String("\"");
}

void block_model::Object::CopyAttributes(const block_model::Object& src) {
    tag_content.str = src.tag_content.str;
    class_attr.vec = src.class_attr.vec;
    hidden = src.hidden;
    title.str = src.title.str;
}
