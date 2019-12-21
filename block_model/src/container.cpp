#include <block_model/container.h>

void block_model::Container::AddObject(const std::shared_ptr<Object>& object) {
  objects_content.push_back(object);
}

void block_model::Container::RemoveObject(const int& id) {
  objects_content[id] = nullptr;
}

block_model::Container::~Container() = default;
