#ifndef TP_LAYOUT_TEMPLATE_ENGINE_BODY_H
#define TP_LAYOUT_TEMPLATE_ENGINE_BODY_H

#include <functional>
#include <vector>
#include "HTML_generator/node.h"

template <typename T>
class Body {
  node<T> root;
  bool empty;

 public:
  Body() : empty(true) {}
  bool IsEmpty() { return empty; }

  node<T>& get() { return root; }
  const node<T>& get() const { return root; }
  node<T>& set(const T& obj) {
    this->root = node(obj);
    return root;
  }
};

#endif  // TP_LAYOUT_TEMPLATE_ENGINE_BODY_H
