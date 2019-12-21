#include <iostream>
#include "block_model/a.h"
#include "block_model/div.h"
#include "block_model/object.h"
#include "html_generator/head.h"
#include "html_generator/templater.h"

std::ostringstream sss(block_model::Object* const& obj) {
  auto map = obj->MakeHtmlString();
  auto&& true_map = map.map;
  std::ostringstream result;
  //  if (first) {
  result << map.tag.str << " ";
  for (auto&& i : true_map) {
    result << i.first << " = '" << i.second << "' ";
  }
  //    }
  //  } else {
  //  }
  //    result << map.tag.str << " ";
  return result;
}
std::ostringstream fff(block_model::Object* const& obj) {
  auto map = obj->MakeHtmlString();
  auto&& true_map = map.map;
  std::ostringstream result;
  result << map.tag.str << " ";
  return result;
}

int main() {
  Head head;
  head.set_author("Lolec Kekovich");
  head.set_title("HTMLTitle");
  head.set_file_name("file");
  head.set_description("desc");

  Body<block_model::Object*> body;

  block_model::Div div;
  auto&& node = body.set(&div);

  block_model::A a;
  //  body.root.add_children_back(&a);
  node.add_children_back(&a);
  Page page(head, body);

  Templater<block_model::Object*> templater;
  auto q = templater.get_full_template(sss, fff, page);
  std::cout << q.str();
  return 0;
}