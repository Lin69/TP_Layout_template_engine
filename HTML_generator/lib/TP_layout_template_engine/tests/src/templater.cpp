#include "HTML_generator/templater.h"
#include "gtest/gtest.h"
typedef boost::variant<Div, List, Img, A_link, Input, Textarea, Button> VarType;

TEST(init_1_1) {
  temp = Templater("file.css", 1, 1);
  res = temp.get_full_template();
  check =
      ".wrapper {\n"
      "    display: grid;\n"
      "    grid-template-columns: repeat(12, 1fr);\n"
      "    grid-auto-rows: minmax(100px, auto);\n"
      "    grid-template-areas: \n"
      "      \"hd hd hd hd hd hd hd hd hd hd hd hd\"\n"
      "      \"main main main main main main main main main main main main\"\n"
      "      \"ft ft ft ft ft ft ft ft ft ft ft ft\";\n"
      "}\n"
      ".header{\n"
      "    grid-area: hd;\n"
      "}\n"
      ".content{\n"
      "    grid-area: main;\n"
      "}\n"
      ".footer{\n"
      "    grid-area: ft;\n"
      "}";
  EXPECT_EQ(res, check);
}
TEST(init_2_1) {
  temp = Templater("file.css", 2, 1);
  res = temp.get_full_template();
  check =
      ".wrapper {\n"
      "    display: grid;\n"
      "    grid-template-columns: repeat(12, 1fr);\n"
      "    grid-auto-rows: minmax(100px, auto);\n"
      "    grid-template-areas: \n"
      "      \"hd hd hd hd hd hd hd hd hd hd hd hd\"\n"
      "      \"left left left left main main main main main main main main\"\n"
      "      \"ft ft ft ft ft ft ft ft ft ft ft ft\";\n"
      "}\n"
      ".header{\n"
      "    grid-area: hd;\n"
      "}\n"
      ".leftbar{\n"
      "    grid-area: left;\n"
      "}\n"
      ".content{\n"
      "    grid-area: main;\n"
      "}\n"
      ".footer{\n"
      "    grid-area: ft;\n"
      "}";
  EXPECT_EQ(res, check);
}
TEST(init_2_2) {
  temp = Templater("file.css", 2, 2);
  res = temp.get_full_template();
  check =
      ".wrapper {\n"
      "    display: grid;\n"
      "    grid-template-columns: repeat(12, 1fr);\n"
      "    grid-auto-rows: minmax(100px, auto);\n"
      "    grid-template-areas: \n"
      "      \"hd hd hd hd hd hd hd hd hd hd hd hd\"\n"
      "      \"main main main main main main main main right right right "
      "right\"\n"
      "      \"ft ft ft ft ft ft ft ft ft ft ft ft\";\n"
      "}\n"
      ".header{\n"
      "    grid-area: hd;\n"
      "}\n"
      ".rightbar{\n"
      "    grid-area: right;\n"
      "}\n"
      ".content{\n"
      "    grid-area: main;\n"
      "}\n"
      ".footer{\n"
      "    grid-area: ft;\n"
      "}";
  EXPECT_EQ(res, check);
}
TEST(init_3_1) {
  temp = Templater("file.css", 3, 1);
  res = temp.get_full_template();
  check =
      ".wrapper {\n"
      "    display: grid;\n"
      "    grid-template-columns: repeat(12, 1fr);\n"
      "    grid-auto-rows: minmax(100px, auto);\n"
      "    grid-template-areas: \n"
      "      \"hd hd hd hd hd hd hd hd hd hd hd hd\"\n"
      "      \"left left left right right right main main main main main "
      "main\"\n"
      "      \"ft ft ft ft ft ft ft ft ft ft ft ft\";\n"
      "}\n"
      ".header{\n"
      "    grid-area: hd;\n"
      "}\n"
      ".rightbar{\n"
      "    grid-area: right;\n"
      "}\n"
      ".leftbar{\n"
      "    grid-area: left;\n"
      "}\n"
      ".content{\n"
      "    grid-area: main;\n"
      "}\n"
      ".footer{\n"
      "    grid-area: ft;\n"
      "}";
  EXPECT_EQ(res, check);
}
TEST(init_3_2) {
  temp = Templater("file.css", 3, 2);
  res = temp.get_full_template();
  check =
      ".wrapper {\n"
      "    display: grid;\n"
      "    grid-template-columns: repeat(12, 1fr);\n"
      "    grid-auto-rows: minmax(100px, auto);\n"
      "    grid-template-areas: \n"
      "      \"hd hd hd hd hd hd hd hd hd hd hd hd\"\n"
      "      \"left left left main main main main main main right right "
      "right\"\n"
      "      \"ft ft ft ft ft ft ft ft ft ft ft ft\";\n"
      "}\n"
      ".header{\n"
      "    grid-area: hd;\n"
      "}\n"
      ".rightbar{\n"
      "    grid-area: right;\n"
      "}\n"
      ".leftbar{\n"
      "    grid-area: left;\n"
      "}\n"
      ".content{\n"
      "    grid-area: main;\n"
      "}\n"
      ".footer{\n"
      "    grid-area: ft;\n"
      "}";
  EXPECT_EQ(res, check);
}
TEST(init_3_3) {
  temp = Templater("file.css", 3, 3);
  res = temp.get_full_template();
  check =
      ".wrapper {\n"
      "    display: grid;\n"
      "    grid-template-columns: repeat(12, 1fr);\n"
      "    grid-auto-rows: minmax(100px, auto);\n"
      "    grid-template-areas: \n"
      "      \"hd hd hd hd hd hd hd hd hd hd hd hd\"\n"
      "      \"main main main main main main left left left right right "
      "right\"\n"
      "      \"ft ft ft ft ft ft ft ft ft ft ft ft\";\n"
      "}\n"
      ".header{\n"
      "    grid-area: hd;\n"
      "}\n"
      ".rightbar{\n"
      "    grid-area: right;\n"
      "}\n"
      ".leftbar{\n"
      "    grid-area: left;\n"
      "}\n"
      ".content{\n"
      "    grid-area: main;\n"
      "}\n"
      ".footer{\n"
      "    grid-area: ft;\n"
      "}";
  EXPECT_EQ(res, check);
}
TEST(WrongParams) {
  EXPECT_THROW(temp = Templater("file.css", 4, 3), std::invalid_argument)
}
