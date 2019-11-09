#include "HTML_generator/body.h"
#include "gtest/gtest.h"
// typedef boost::variant<Div, List, Img, A_link, Input, Textarea, Button>
// VarType;
typedef int VarType;
TEST(body, init) {
  Body body(1);
  Div d;
  d.set_class("header");
  VarType res = body.get_content("1");
  EXPECT_EQ(res, d);
}
TEST(body, adding) {
  Body body(1);
  Div d;
  body.add_content("1", d);
  VarType res = body.get_content("4");
  EXPECT_EQ(res, d);
}
TEST(body, NotFoundElement) {
  Body body(1);
  Div d;
  EXPECT_THROW(VarType res = body.get_content("4"), std::out_of_range)
}
TEST(body, del) {
  Body body(1);
  Div d;
  body.add_content("1", d);
  body.delete_object("4");
  EXPECT_THROW(VarType res = body.get_content("4"), std::out_of_range)
}
TEST(body, get_all) {
  Body body(1);
  Div d;
  string res = body.get_all();
  check =
      "<div class=\"header\">Header</div>\n<div "
      "class=\"content\">Content</div>\n<div class=\"footer\">Footer</div>";
  EXPECT_EQ(res, check);
}
