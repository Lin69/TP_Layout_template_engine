#ifndef TP_LAYOUT_TEMPLATE_ENGINE_CONTAINER_H
#define TP_LAYOUT_TEMPLATE_ENGINE_CONTAINER_H

#include "Object.h"

class Container : public Object {
public:
    template<typename T>
    void add_object(const T& object);

    void remove_object(const int& id);

protected:
    std::vector<std::shared_ptr<Object>> objects_content;
};

template<typename T>
void Container::add_object(const T& object) {

}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_CONTAINER_H
