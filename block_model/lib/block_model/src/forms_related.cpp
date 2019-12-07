#include <forms_related.h>

void block_model::FormsRelated::SetFormPtr(std::shared_ptr<Form> new_form_ptr) {
    form_ptr = std::move(new_form_ptr);
}

block_model::FormsRelated::~FormsRelated() = default;
