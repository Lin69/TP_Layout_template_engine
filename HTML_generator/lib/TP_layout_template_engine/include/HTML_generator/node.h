#ifndef TP_LAYOUT_TEMPLATE_ENGINE_ROOT_H
#define TP_LAYOUT_TEMPLATE_ENGINE_ROOT_H

#include <functional>
#include <stack>
#include <utility>
#include <vector>

template <typename T>
class node {
  T obj;
  std::vector<node<T>> children;

 public:
  using TypeFunction = std::function<void(const T&)>;

  explicit node(T obj) { std::swap(this->obj, obj); }
  node() = default;
  node<T>& add_children_back(const T& obj) {
    children.push_back(node(obj));
    return children.back();
  }

  void postOrderIterative(const TypeFunction& func_first_visit,
                          const TypeFunction& func_second_visit) const {
    std::stack<std::pair<const node<T>*, bool>> stack;

    auto load = [&](const node<T>& node) {
      auto&& range = node.children;
      auto begin = range.crbegin();
      auto end = range.crend();
      for (; begin != end; ++begin) {
        stack.push({&(*begin), false});
      }
    };

    stack.push({this, false});
    while (!stack.empty()) {
      auto& current = stack.top();

      auto& current_node = current.first;
      auto& is_visit = current.second;

      if (is_visit == false) {
        func_first_visit(current_node->obj);
        is_visit = true;
        if (!current_node->children.empty()) {
          load(*current_node);
        }
      } else {
        func_second_visit(current_node->obj);
        stack.pop();
      }
    }
  }
};
#endif  // TP_LAYOUT_TEMPLATE_ENGINE_ROOT_H
