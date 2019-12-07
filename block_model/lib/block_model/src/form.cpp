#include "form.h"

block_model::Form::Form() : http_method(false) {

}

block_model::Form::Form(const block_model::Form& src) {
    tag_content.str = src.tag_content.str;
    class_attr.vec = src.class_attr.vec;
    hidden = src.hidden;
    title.str = src.title.str;

    objects_content = src.objects_content;
    http_method = src.http_method;
    action_attr = src.action_attr;
}

block_model::Form::Form(block_model::Form&& src) noexcept {
    tag_content.str = std::move(src.tag_content.str);
    class_attr.vec = std::move(src.class_attr.vec);
    hidden = src.hidden;
    title.str = std::move(src.title.str);

    objects_content = std::move(src.objects_content);
    http_method = src.http_method;
    action_attr = std::move(src.action_attr);

    id_attr = ----id_count;
}

block_model::Form &block_model::Form::operator=(const block_model::Form& src) {
    tag_content.str = src.tag_content.str;
    class_attr.vec = src.class_attr.vec;
    hidden = src.hidden;
    title.str = src.title.str;

    objects_content = src.objects_content;
    http_method = src.http_method;
    action_attr = src.action_attr;

    return *this;
}

block_model::Form::~Form() = default;

void block_model::Form::SetAction(const block_model::string& new_action) {
    action_attr.str = new_action.str;
}

void block_model::Form::SetHttpMethod(const bool& value) {
    http_method = value;
}

void block_model::Form::SetTagContent(const block_model::string& new_content) {

}

block_model::string block_model::Form::MakeHtmlString() const {
    block_model::string result("<form");

    if (http_method) {
        result + block_model::string(" method=\"post\"");
    }

    if (!action_attr.is_empty()) {
        WrapAttribute(result, block_model::string("action"), action_attr);
    }

    CheckAttributes(result);
    result + block_model::string("\n");

    for (const auto& it : objects_content) {
        if (it) {
            result + it->MakeHtmlString();
            result + block_model::string("\n");
        }
    }

    result + block_model::string("</form>");

    return result;
}

int block_model::Form::GetId() const {
    return id_attr;
}
