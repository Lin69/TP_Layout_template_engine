#include <ol_creator.h>

std::shared_ptr<block_model::Object> block_model::OlCreator::Create() {
    return std::make_shared<Ol>();
}
