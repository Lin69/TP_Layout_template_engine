//
// Created by Lina on 08/11/2019.
//

#ifndef TP_LAYOUT_TEMPLATE_ENGINE_PAGER_H
#define TP_LAYOUT_TEMPLATE_ENGINE_PAGER_H

#include <map>
#include <string>
#include "HTML_generator/body.h"
#include "HTML_generator/head.h"
#include "HTML_generator/templater.h"
#include "boost/variant.hpp"

using std::map;
using std::string;

class Pager {
 private:
  Templater css_template;
  Head head;
  Body body;

 public:
  Pager(string, int, int);
  void alter_head(map<string, string>);

  void add_to_body(string, VarType);
  void remove_from_body(string);
  VarType get_element(string);
  void render();
};

#endif  // TP_LAYOUT_TEMPLATE_ENGINE_PAGER_H
