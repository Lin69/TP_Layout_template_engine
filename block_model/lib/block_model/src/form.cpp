#include "form.h"

block_model::Form::Form() : http_method(false) {

}

block_model::Form::Form(const block_model::Form& src) = default;

block_model::Form::Form(block_model::Form&& src) noexcept : Object(std::move(src)), http_method(src.http_method),
                                                            action_attr(std::move(src.action_attr)) {
    objects_content = std::move(src.objects_content);
}

block_model::Form &block_model::Form::operator=(const block_model::Form& src) {
    if (this == &src) {
        return *this;
    }

    CopyAttributes(src);
    objects_content = src.objects_content;
    http_method = src.http_method;
    action_attr = src.action_attr;

    return *this;
}

block_model::Form::~Form() = default;

void block_model::Form::SetAction(const block_model::String& new_action) {
    action_attr.str = new_action.str;
}

void block_model::Form::SetHttpMethod(const bool& value) {
    http_method = value;
}

void block_model::Form::SetTagContent(const block_model::String& new_content) {

}

block_model::String block_model::Form::MakeHtmlString() const {
    block_model::String result("<form");

    if (http_method) {
        result + block_model::String(" method=\"post\"");
    }

    if (!action_attr.is_empty()) {
        WrapAttribute(result, block_model::String("action"), action_attr);
    }

    CheckAttributes(result);
    result + block_model::String("\n");

    for (const auto& it : objects_content) {
        if (it) {
            result + it->MakeHtmlString();
            result + block_model::String("\n");
        }
    }

    result + block_model::String("</form>");

    return result;
}

int block_model::Form::GetId() const {
    return id_attr;
}
