#include <select_creator.h>

std::shared_ptr<block_model::Object> block_model::SelectCreator::Create() {
    return std::make_shared<Select>();
}
