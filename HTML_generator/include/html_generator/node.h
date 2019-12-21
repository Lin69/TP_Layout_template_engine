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
  node() : obj(), children(){};
  node(const node& node) : obj(node.obj), children(node.children) {}
  node(node&& node) noexcept : obj(node.obj), children(node.children) {
    while (node.children.size() > 0) {
      node.children.pop_back();
    }
    node.obj = NULL;
  }
  //  void add_children_back(const T& obj) { children.push_back(node(obj)); }
  node<T>& add_children_back(const T& obj) {
    children.push_back(node(obj));
    return children.back();
  }

  node& operator=(const node& other) {
    obj = other.obj;
    children = other.children;
    return *this;
  }

  node& operator=(node&& other) noexcept {
    obj = other.obj;
    children = other.children;
    return *this;
  }

  void postOrderIterative(const TypeFunction& func_first_visit,
                          const TypeFunction& func_second_visit) const {
    func_first_visit(this->obj);
    for (auto&& i : children) {
      i.postOrderIterative(func_first_visit, func_second_visit);
    }
    func_second_visit(this->obj);
    //    std::stack<std::pair<const node<T>*, bool>> stack;

    //    auto load = [&](const node<T>& node) {
    //      auto&& range = node.children;
    //      auto begin = range.crbegin();
    //      auto end = range.crend();
    //      for (; begin != end; ++begin) {
    //        stack.push({&(*begin), false});
    //      }
    //    };
    //
    //    stack.push({this, false});
    //    while (!stack.empty()) {
    //      auto& current = stack.top();
    //
    //      auto& current_node = current.first;
    //      auto& is_visit = current.second;
    //
    //      if (is_visit == false) {
    //        func_first_visit(current_node->obj);
    //        is_visit = true;
    //        if (!current_node->children.empty()) {
    //          load(*current_node);
    //        }
    //      } else {
    //        func_second_visit(current_node->obj);
    //        stack.pop();
    //      }
    //    }
  }
};
#endif  // TP_LAYOUT_TEMPLATE_ENGINE_ROOT_H
