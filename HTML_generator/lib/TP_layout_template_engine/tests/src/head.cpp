#include "HTML_generator/head.h"
#include "gtest/gtest.h"

TEST(Setting_title) {
  Head h;
  h.set_title("Title");
  res = get_title();
  EXPECT_EQ(res, "Title");
}
TEST(Setting_author) {
  Head h;
  h.set_author("Author");
  res = get_author();
  EXPECT_EQ(res, "Author");
}
TEST(Setting_description) {
  Head h;
  h.set_title("Description");
  res = get_description();
  EXPECT_EQ(res, "Description");
}
TEST(Setting_file_name) {
  Head h;
  h.set_file_name("File_name");
  res = get_file_name();
  EXPECT_EQ(res, "File_name");
}
TEST(Get_head) {
  Head h;
  h.set_title("Title");
  h.set_author("Author");
  h.set_title("Description");
  h.set_file_name("File_name");
  res = get_html_head();
  check =
      "<head>\n"
      "    <title>Title</title>\n"
      "    <meta name=\"description\" content=\"Description\">\n"
      "    <meta name=\"author\" content=\"Author\">\n"
      "    <link rel=\"stylesheet\" href=\"File_name\">\n"
      "</head>";
  EXPECT_EQ(res, check);
}