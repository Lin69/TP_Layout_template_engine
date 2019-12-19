#include <textarea.h>

block_model::Textarea::Textarea() : cols(0), rows(0), maxlength(0), readonly(false), required_attr(false) {

}

block_model::Textarea::Textarea(const block_model::Textarea& src) = default;

block_model::Textarea::Textarea(block_model::Textarea&& src) noexcept : Object(std::move(src)), cols(src.cols),
                                                                        rows(src.rows), maxlength(src.maxlength),
                                                                        readonly(src.readonly),
                                                                        required_attr(src.required_attr) {
    form_ptr = std::move(src.form_ptr);
}

block_model::Textarea& block_model::Textarea::operator=(const block_model::Textarea& src) {
    if (this == &src) {
        return *this;
    }

    CopyAttributes(src);
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

void block_model::Textarea::SetPlaceholder(const block_model::String& new_placeholder) {
    placeholder.str = new_placeholder.str;
}

void block_model::Textarea::SetReadonly(const bool& value) {
    readonly = value;
}

void block_model::Textarea::SetRequired(const bool& value) {
    required_attr = value;
}

block_model::String block_model::Textarea::MakeHtmlString() const {
    block_model::String result("<textarea");

    if (cols) {
        WrapAttribute(result, block_model::String("cols"), cols);
    }

    if (rows) {
        WrapAttribute(result, block_model::String("rows"), rows);
    }

    if (maxlength) {
        if (cols) {
            WrapAttribute(result, block_model::String("maxlength"), maxlength);
        }
    }

    if (!placeholder.is_empty()) {
        WrapAttribute(result, block_model::String("placeholder"), placeholder);
    }

    if (readonly) {
        result + block_model::String(" readonly");
    }

    if (required_attr) {
        result + block_model::String(" required");
    }

    if (form_ptr) {
        WrapAttribute(result, block_model::String("form"), form_ptr->GetId());
    }

    CheckAttributes(result);

    result + block_model::String("</textarea>");

    return result;
}




