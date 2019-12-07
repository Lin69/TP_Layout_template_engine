#include <input.h>

block_model::Input::Input() : type_attr(submit) {

}

block_model::Input::Input(const block_model::Input& src) {
    tag_content.str = src.tag_content.str;
    class_attr.vec = src.class_attr.vec;
    hidden = src.hidden;
    title.str = src.title.str;

    form_ptr = src.form_ptr;
    type_attr = src.type_attr;
    value_attr.str = src.value_attr.str;
}

block_model::Input::Input(block_model::Input&& src) noexcept {
    tag_content.str = std::move(src.tag_content.str);
    class_attr.vec = std::move(src.class_attr.vec);
    hidden = src.hidden;
    title.str = std::move(src.title.str);

    form_ptr = std::move(src.form_ptr);
    type_attr = src.type_attr;
    value_attr.str = std::move(src.value_attr.str);

    id_attr = ----id_count;
}

block_model::Input &block_model::Input::operator=(const block_model::Input& src) {
    tag_content.str = src.tag_content.str;
    class_attr.vec = src.class_attr.vec;
    hidden = src.hidden;
    title.str = src.title.str;

    form_ptr = src.form_ptr;
    type_attr = src.type_attr;
    value_attr.str = src.value_attr.str;

    return *this;
}

block_model::Input::~Input() = default;

void block_model::Input::SetType(const block_model::object_type& type) {
    type_attr = type;
}

void block_model::Input::SetValue(const block_model::string& new_value) {
    value_attr.str = new_value.str;
}

block_model::string block_model::Input::MakeHtmlString() const {
    block_model::string result("<input type=\"");

    switch (type_attr) {
        case button: {
            result + block_model::string("button\"");
            break;
        }

        case checkbox: {
            result + block_model::string("checkbox\"");
            break;
        }

        case file_attr: {
            result + block_model::string("file\"");
            break;
        }

        case hidden_attr: {
            result + block_model::string("hidden\"");
            break;
        }

        case image: {
            result + block_model::string("image\"");
            break;
        }

        case password: {
            result + block_model::string("password\"");
            break;
        }

        case radio: {
            result + block_model::string("radio\"");
            break;
        }

        case reset_attr: {
            result + block_model::string("reset\"");
            break;
        }

        case submit: {
            result + block_model::string("submit\"");
            break;
        }

        case text_attr: {
            result + block_model::string("text\"");
            break;
        }

        default: {
            break;
        }
    }

    if (!value_attr.is_empty()) {
        WrapAttribute(result, block_model::string("value"), value_attr);
    }

    if (form_ptr) {
        WrapAttribute(result, block_model::string("form"), form_ptr->GetId());
    }

    CheckAttributes(result);

    return result;
}




