#include <a_creator.h>

std::shared_ptr<block_model::Object> block_model::ACreator::Create() {
    return std::make_shared<A>();
}
