#include <form_creator.h>

std::shared_ptr<block_model::Object> block_model::FormCreator::Create() {
    return std::make_shared<Form>();
}
