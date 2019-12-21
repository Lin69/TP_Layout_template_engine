#include <container.h>

void block_model::Container::AddObject(const std::shared_ptr<Object>& object) {
    objects_content.push_back(object);
}

void block_model::Container::RemoveObject(const int& id) {
    for (const auto& it : objects_content) {
        if (it->GetId() == id) {
            objects_content.remove(it);
            break;
        }
    }
}

block_model::Container::~Container() = default;
