#ifndef TP_LAYOUT_TEMPLATE_ENGINE_LIST_H
#define TP_LAYOUT_TEMPLATE_ENGINE_LIST_H

#include "object.h"

namespace block_model {
    class List {
    public:
        void SetList(const vector<string>& new_list);
        void ListAppend(const string& item);
        void ListRemove(const int& id);

        virtual ~List();

    protected:
        vector<string> list_content;
    };
}

#endif //TP_LAYOUT_TEMPLATE_ENGINE_LIST_H
