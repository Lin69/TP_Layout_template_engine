#ifndef TP_LAYOUT_TEMPLATE_ENGINE_PAGE_H
#define TP_LAYOUT_TEMPLATE_ENGINE_PAGE_H

#include "HTML_generator/body.h"
#include "HTML_generator/head.h"

template <typename T>
class Page {
  Head head;
  Body<T> body;

 public:
  Page(Head head, Body<T> body) {
    std::swap(this->head, head);
    std::swap(this->body, body);
  }
  Head& get_head() { return head; }
  Body<T>& get_body() { return body; }
  const Head& get_head() const { return head; }
  const Body<T>& get_body() const { return body; }
};

#endif  // TP_LAYOUT_TEMPLATE_ENGINE_PAGE_H
