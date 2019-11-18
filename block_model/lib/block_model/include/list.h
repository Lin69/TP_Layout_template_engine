#ifndef TP_LAYOUT_TEMPLATE_ENGINE_LIST_H
#define TP_LAYOUT_TEMPLATE_ENGINE_LIST_H

#include "object.h"

class List {
public:
    void SetList(const std::vector<std::string>& new_list);
    void ListAppend(const std::string& item);
    void ListRemove(const int& id);

protected:
    std::vector<std::string> list_content;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_LIST_H
