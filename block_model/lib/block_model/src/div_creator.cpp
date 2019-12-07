#include <div_creator.h>

std::shared_ptr<block_model::Object> block_model::DivCreator::Create() {
    return std::make_shared<Div>();
}
