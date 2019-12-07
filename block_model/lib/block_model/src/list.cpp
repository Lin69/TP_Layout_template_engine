#include <list.h>

block_model::List::~List() = default;

void block_model::List::SetList(const block_model::vector<block_model::string>& new_list) {
    list_content.vec = new_list.vec;
}

void block_model::List::ListAppend(const block_model::string& item) {
    list_content.vec.push_back(item);
}

void block_model::List::ListRemove(const int& id) {
    block_model::vector<string> tmp;
    list_content.vec[id] = block_model::string();

    for (const auto& it : list_content.vec) {
        if (!it.is_empty()) {
            tmp.vec.push_back(it);
        }
    }

    list_content.vec = std::move(tmp.vec);
}
