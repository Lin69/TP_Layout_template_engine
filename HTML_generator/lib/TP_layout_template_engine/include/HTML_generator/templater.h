#ifndef TP_LAYOUT_TEMPLATE_ENGINE_TEMPLATER_H
#define TP_LAYOUT_TEMPLATE_ENGINE_TEMPLATER_H

#include <functional>
#include <sstream>
#include "HTML_generator/page.h"

template <typename T>
class Templater {
  std::ostringstream head(const Page<T>& page) {
    std::ostringstream result;

    result << "<head>";
    const Head& head = page.get_head();
    for (auto&& i : head) {
      result << '<' << i.first << '>' << *(i.second) << "</" << i.first + '>';
    }
    result << "</head>";

    return result;
  }

  std::ostringstream body(
      const std::function<std::ostringstream(const T&)>& func,
      const Page<T>& page) {
    std::ostringstream result;

    result << "<body>";

    auto void_func_first_visit = [&](const T& t) {
      result << '<' << func(t).str() << '>';
    };
    auto void_func_second_visit = [&](const T& t) {
      result << "</" << func(t).str() << '>';
    };
    page.get_body().get().postOrderIterative(void_func_first_visit,
                                             void_func_second_visit);

    result << "</body>";

    return result;
  }

 public:
  std::ostringstream get_full_template(
      const std::function<std::ostringstream(const T&)>& func,
      const Page<T>& page) {
    std::ostringstream result;
    result << "<html>";
    result << head(page).str();
    result << body(func, page).str();
    result << "</html>";
    return result;
  };
};

#endif  // TP_LAYOUT_TEMPLATE_ENGINE_TEMPLATER_H
