#include "HTML_generator/pager.h"

Pager::Pager(string file_name, int num_cols, int template_num)
    : css_template(Templater(file_name, num_cols, template_num)){};
void Pager::alter_head(map<string, string>){};

void Pager::add_to_body(boost::variant<int, string> object){};
string Pager::get_name() { return ""; };
void Pager::change_name(string new_name){};
void Pager::remove_from_body(string id){};

boost::variant<int, string> Pager::get_element(string id) {
  boost::variant<int, string> v;
  return v;
};
string Pager::render() { return ""; };