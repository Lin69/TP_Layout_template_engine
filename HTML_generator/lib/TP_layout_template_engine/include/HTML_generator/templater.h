//
// Created by Lina on 08/11/2019.
//

#ifndef TP_LAYOUT_TEMPLATE_ENGINE_TEMPLATER_H
#define TP_LAYOUT_TEMPLATE_ENGINE_TEMPLATER_H

#include <string>

using std::string;

class Templater {
 private:
  int number_of_columns;
  int number_of_template;
  string header;
  string content;
  string footer;
  void create_template();

 public:
  Templater(string, int, int);
  void create_css();
  string get_full_template();
};

#endif  // TP_LAYOUT_TEMPLATE_ENGINE_TEMPLATER_H
