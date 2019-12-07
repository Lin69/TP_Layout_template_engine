#include <img_creator.h>

std::shared_ptr<block_model::Object> block_model::ImgCreator::Create() {
    return std::make_shared<Img>();
}
