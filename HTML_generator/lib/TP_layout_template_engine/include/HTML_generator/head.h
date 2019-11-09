//
// Created by Lina on 08/11/2019.
//

#ifndef TP_LAYOUT_TEMPLATE_ENGINE_HEAD_H
#define TP_LAYOUT_TEMPLATE_ENGINE_HEAD_H

#include <string>
#include <vector>
using std::string;
using std::vector;
class Head {
 private:
  string title;
  string author;
  string description;
  string css_file_name;

 public:
  void set_title(string);
  void set_author(string);
  void set_description(string);
  void set_file_name(string);
  string get_title();
  string get_author();
  string get_description();
  string get_file_name();
  string get_html_head();
};
#endif  // TP_LAYOUT_TEMPLATE_ENGINE_HEAD_H
