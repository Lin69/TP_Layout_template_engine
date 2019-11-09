#include "HTML_generator/body.h"
#include "gtest/gtest.h"
typedef boost::variant<Div, List, Img, A_link, Input, Textarea, Button> VarType;

TEST(init) {
  body = Body(1);
  Div d;
  d.set_class("header");
  VarType res = body.get_content("1");
  EXPECT_EQ(res, d);
}
TEST(adding) {
  body = Body(1);
  Div d;
  body.add_content("1", d);
  VarType res = body.get_content("4");
  EXPECT_EQ(res, d);
}
TEST(NotFoundElement) {
  body = Body(1);
  Div d;
  EXPECT_THROW(VarType res = body.get_content("4"), std::out_of_range)
}
TEST(del) {
  body = Body(1);
  Div d;
  body.add_content("1", d);
  body.delete_object("4");
  EXPECT_THROW(VarType res = body.get_content("4"), std::out_of_range)
}
TEST(get_all) {
  body = Body(1);
  Div d;
  string res = body.get_all();
  check =
      "<div class=\"header\">Header</div>\n<div "
      "class=\"content\">Content</div>\n<div class=\"footer\">Footer</div>";
  EXPECT_EQ(res, check);
}
