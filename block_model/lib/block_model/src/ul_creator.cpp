#include <ul_creator.h>

std::shared_ptr<block_model::Object> block_model::UlCreator::Create() {
    return std::make_shared<Ul>();
}
