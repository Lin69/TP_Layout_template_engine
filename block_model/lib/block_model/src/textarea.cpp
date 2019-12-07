#include <textarea.h>

block_model::Textarea::Textarea() : cols(0), rows(0), maxlength(0), readonly(false), required_attr(false) {

}

block_model::Textarea::Textarea(const block_model::Textarea& src) {
    tag_content.str = src.tag_content.str;
    class_attr.vec = src.class_attr.vec;
    hidden = src.hidden;
    title.str = src.title.str;

    form_ptr = src.form_ptr;
    cols = src.cols;
    rows = src.rows;
    maxlength = src.maxlength;
    readonly = src.readonly;
    required_attr = src.required_attr;
}

block_model::Textarea::Textarea(block_model::Textarea&& src) noexcept {
    tag_content.str = std::move(src.tag_content.str);
    class_attr.vec = std::move(src.class_attr.vec);
    hidden = src.hidden;
    title.str = std::move(src.title.str);

    form_ptr = std::move(src.form_ptr);
    cols = src.cols;
    rows = src.rows;
    maxlength = src.maxlength;
    readonly = src.readonly;
    required_attr = src.required_attr;

    id_attr = ----id_count;
}

block_model::Textarea& block_model::Textarea::operator=(const block_model::Textarea& src) {
    tag_content.str = src.tag_content.str;
    class_attr.vec = src.class_attr.vec;
    hidden = src.hidden;
    title.str = src.title.str;

    form_ptr = src.form_ptr;
    cols = src.cols;
    rows = src.rows;
    maxlength = src.maxlength;
    readonly = src.readonly;
    required_attr = src.required_attr;

    return *this;
}

block_model::Textarea::~Textarea() = default;

void block_model::Textarea::SetCols(const int& new_cols) {
    cols = new_cols;
}

void block_model::Textarea::SetRows(const int& new_rows) {
    rows = new_rows;
}

void block_model::Textarea::SetMaxlength(const int& new_maxlength) {
        maxlength = new_maxlength;
}

void block_model::Textarea::SetPlaceholder(const block_model::string& new_placeholder) {
    placeholder.str = new_placeholder.str;
}

void block_model::Textarea::SetReadonly(const bool& value) {
    readonly = value;
}

void block_model::Textarea::SetRequired(const bool& value) {
    required_attr = value;
}

block_model::string block_model::Textarea::MakeHtmlString() const {
    block_model::string result("<textarea");

    if (cols) {
        WrapAttribute(result, block_model::string("cols"), cols);
    }

    if (rows) {
        WrapAttribute(result, block_model::string("rows"), rows);
    }

    if (maxlength) {
        if (cols) {
            WrapAttribute(result, block_model::string("maxlength"), maxlength);
        }
    }

    if (!placeholder.is_empty()) {
        WrapAttribute(result, block_model::string("placeholder"), placeholder);
    }

    if (readonly) {
        result + block_model::string(" readonly");
    }

    if (required_attr) {
        result + block_model::string(" required");
    }

    if (form_ptr) {
        WrapAttribute(result, block_model::string("form"), form_ptr->GetId());
    }

    CheckAttributes(result);

    result + block_model::string("</textarea>");

    return result;
}




