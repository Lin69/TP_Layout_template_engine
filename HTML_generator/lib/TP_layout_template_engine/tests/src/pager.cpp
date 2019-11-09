#include "HTML_generator/pager.h"
#include "gtest/gtest.h"
// typedef boost::variant<Div, List, Img, A_link, Input, Textarea, Button>
// VarType;
typedef int VarType;
TEST(init_er) {
  EXPECT_THROW(pager = Pager("file", 4, 1), std::invalid_argument);
}
TEST(adding) {
  pager = Pager("file", 1, 1);
  Div d;
  pager.add_to_body("1", d);
  VarType res = pager.get_element("4");
  EXPECT_EQ(res, d);
}
TEST(adding_er) {
  pager = Pager("file", 1, 1);
  Div d;
  EXPECT_THROW(pager.add_to_body("0", d), std::invalid_argument);
}
TEST(removing) {
  pager = Pager("file", 1, 1);
  Div d;
  pager.add_to_body("1", d);
  pager.remove_from_body("4");
  EXPECT_THROW(VarType res = pager.get_element("4"), std::out_of_range);
}