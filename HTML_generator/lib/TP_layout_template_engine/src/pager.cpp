#include "HTML_generator/pager.h"

Pager::Pager(string file_name, int num_cols, int template_num)
    : css_template(Templater(file_name, num_cols, template_num)){};
void Pager::alter_head(map<string, string>){};

void Pager::add_to_body(string container_id, VarType object){};
void Pager::remove_from_body(string id){};

VarType Pager::get_element(string id) {
  VarType v;
  return v;
};
string Pager::render(){};