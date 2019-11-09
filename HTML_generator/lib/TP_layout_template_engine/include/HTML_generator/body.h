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

// typedef boost::variant<Div, List, Img, A_link, Input, Textarea, Button>
// VarType;
typedef int VarType;

class Body {
 private:
  int elements_count;
  vector<VarType> content;

 public:
  Body(int);
  void add_content(string, VarType);
  VarType get_object(string);
  void delete_object(string);
  string get_all();
};

#endif  // TP_LAYOUT_TEMPLATE_ENGINE_BODY_H
