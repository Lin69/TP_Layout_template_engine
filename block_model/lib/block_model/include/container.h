#ifndef TP_LAYOUT_TEMPLATE_ENGINE_CONTAINER_H
#define TP_LAYOUT_TEMPLATE_ENGINE_CONTAINER_H

#include "object.h"

class Container {
public:
    template<typename T>
    void AddObject(const T& object);

    void RemoveObject(const int& id);

protected:
    std::vector<std::shared_ptr<Object>> objects_content;
};

template<typename T>
void Container::AddObject(const T& object) {

}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_CONTAINER_H
