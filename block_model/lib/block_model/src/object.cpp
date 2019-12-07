#include <object.h>

block_model::Object::Object() : id_attr(id_count++), hidden(false) {

}

block_model::Object::~Object() = default;

void block_model::Object::SetTagContent(const block_model::string& new_content) {
    tag_content.str = new_content.str;
}

void block_model::Object::SetClass(const block_model::string& new_class) {
    class_attr.vec.clear();
    class_attr.vec.push_back(new_class);
}

void block_model::Object::SetClass(const block_model::vector<block_model::string>& new_class) {
    class_attr.vec = new_class.vec;
}

void block_model::Object::SetHidden(const bool& value = true) {
    hidden = value;
}

void block_model::Object::SetTitle(const block_model::string& new_title) {
    title.str = new_title.str;
}

void block_model::Object::CheckAttributes(block_model::string& result) const {
    result + block_model::string(" id=\"");
    result + block_model::string(id_attr);
    result + block_model::string("\"");

    if (!class_attr.is_empty()) {
        result + block_model::string(" class=\"");
        for (const auto& it : class_attr.vec) {
            result + it;

            if (it.str != class_attr.vec.back().str) {
                result + block_model::string(" ");
            }
        }
        result + block_model::string("\"");
    }

    if (hidden) {
        result + block_model::string(" hidden");
    }

    if (!title.is_empty()) {
        result + block_model::string(" title=\"");
        result + title;
        result + block_model::string("\"");
    }

    result + block_model::string(">");
    result + tag_content;
}

int block_model::Object::id_count = 0;

void block_model::Object::WrapAttribute(block_model::string& result, const block_model::string& attribute,
                                        const block_model::string& value) const {
    result + block_model::string(" ");
    result + attribute;
    result + block_model::string("=\"");
    result + value;
    result + block_model::string("\"");
}

void block_model::Object::WrapAttribute(block_model::string& result, const block_model::string& attribute,
                                        const int& value) const {
    result + block_model::string(" ");
    result + attribute;
    result + block_model::string("=\"");
    result + block_model::string(value);
    result + block_model::string("\"");
}
