#include <input_creator.h>

std::shared_ptr<block_model::Object> block_model::InputCreator::Create() {
    return std::shared_ptr<Input>();
}
