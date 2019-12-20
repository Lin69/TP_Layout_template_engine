#include <forms_related.h>

#include <utility>

void block_model::FormsRelated::SetFormPtr(const std::shared_ptr<Form>& new_form_ptr) {
    form_ptr = new_form_ptr;
}

block_model::FormsRelated::~FormsRelated() = default;
