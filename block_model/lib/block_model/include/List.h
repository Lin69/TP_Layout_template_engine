#ifndef TP_LAYOUT_TEMPLATE_ENGINE_LIST_H
#define TP_LAYOUT_TEMPLATE_ENGINE_LIST_H

#include "Object.h"

class List : public Object {
public:
    void set_list(const std::vector<std::string>& new_list);
    void list_append(const std::string& item);
    void list_remove(const int& id);

protected:
    std::vector<std::string> list_content;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_LIST_H
