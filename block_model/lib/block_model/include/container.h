#ifndef TP_LAYOUT_TEMPLATE_ENGINE_CONTAINER_H
#define TP_LAYOUT_TEMPLATE_ENGINE_CONTAINER_H

#include "object.h"

namespace block_model {
    class Container {
    public:
        void AddObject(const std::shared_ptr<Object>& object);

        void RemoveObject(const int& id);

        virtual ~Container();

    protected:
        std::list<std::shared_ptr<Object>> objects_content;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_CONTAINER_H
