#include "HTML_generator/templater.h"
#include "gtest/gtest.h"

std::ostringstream sss(const std::string& obj) {
  return std::ostringstream(obj);
}

TEST(init_1_1, sdhbdf) {
  Head head;
  head.set_author("Lolec Kekovich");
  head.set_title("HTMLTitle");
  head.set_file_name("file");
  head.set_description("desc");

  Body<std::string> body;
  auto& node = body.set("first node ");
  node.add_children_back("children");
  Page page(head, body);

  Templater<std::string> templater;
  auto q = templater.get_full_template(sss, page);
  std::string result(q.str());
  EXPECT_EQ(result, "dsfds");
}