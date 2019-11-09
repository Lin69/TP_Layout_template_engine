//
// Created by Lina on 08/11/2019.
//

#ifndef TP_LAYOUT_TEMPLATE_ENGINE_BODY_H
#define TP_LAYOUT_TEMPLATE_ENGINE_BODY_H
#include <string>
#include <vector>
#include "boost/variant.hpp"
using std::string;
using std::vector;

class Body {
 private:
  int elements_count;
  vector<boost::variant<int, string>> content;

 public:
  void add_content(string, boost::variant<int, string>);
  boost::variant<int, string> get_object(string);
  void delete_object(string);
  vector<string> get_all();
};

#endif  // TP_LAYOUT_TEMPLATE_ENGINE_BODY_H
