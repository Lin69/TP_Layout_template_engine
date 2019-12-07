#include <button_creator.h>

std::shared_ptr<block_model::Object> block_model::ButtonCreator::Create() {
    return std::make_shared<Button>();
}
