#include "HTML_generator/body.h"

void Body::add_content(string container_id,
                       boost::variant<int, string> object){};
boost::variant<int, string> Body::get_object(string id) {
  boost::variant<int, string> v;
  return v;
};
void Body::delete_object(string id){};
vector<string> Body::get_all() { return vector<string>(); };