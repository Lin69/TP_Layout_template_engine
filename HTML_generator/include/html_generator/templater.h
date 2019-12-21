#ifndef TP_LAYOUT_TEMPLATE_ENGINE_TEMPLATER_H
#define TP_LAYOUT_TEMPLATE_ENGINE_TEMPLATER_H

#include <functional>
#include <iostream>
#include <sstream>
#include "html_generator/page.h"

template <typename T>
class Templater {
  std::ostringstream head(const Page<T>& page) {
    std::ostringstream result;

    result << "<head>" << std::endl;
    const Head& head = page.get_head();
    for (auto&& i : head) {
      result << '<' << i.first << '>' << *(i.second) << "</" << i.first + '>'
             << std::endl;
    }
    result << "</head>" << std::endl;

    return result;
  }

  std::ostringstream body(
      const std::function<std::ostringstream(const T&)>& func1,
      const std::function<std::ostringstream(const T&)>& func2,
      const Page<T>& page) {
    std::ostringstream result;

    result << "<body>" << std::endl;

    auto void_func_first_visit = [&](const T& t) {
      result << '<' << func1(t).str() << '>' << std::endl;
    };
    auto void_func_second_visit = [&](const T& t) {
      result << "</" << func2(t).str() << '>' << std::endl;
    };
    page.get_body().get().postOrderIterative(void_func_first_visit,
                                             void_func_second_visit);

    result << "</body>" << std::endl;

    return result;
  }

 public:
  std::ostringstream get_full_template(
      const std::function<std::ostringstream(const T&)>& func1,
      const std::function<std::ostringstream(const T&)>& func2,
      const Page<T>& page) {
    std::ostringstream result;
    result << "<html>" << std::endl;
    result << head(page).str();
    result << body(func1, func2, page).str();
    result << "</html>" << std::endl;
    return result;
  };
};

#endif  // TP_LAYOUT_TEMPLATE_ENGINE_TEMPLATER_H
