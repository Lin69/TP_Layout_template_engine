#include <textarea_creator.h>

std::shared_ptr<block_model::Object> block_model::TextareaCreator::Create() {
    return std::make_shared<Textarea>();
}
