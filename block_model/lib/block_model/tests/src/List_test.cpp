#include "Object.h"
#include "gtest/gtest.h"

TEST(Ol, init) {
    Ol ol{};
    std::string pure_ol("<ol></ol>");
    EXPECT_EQ(ol.make_html_string(), pure_ol);
}

TEST(Ol, set_list) {
    Ol ol{};

    std::vector<std::string> list = {"test1", "test2", "test3"};

    ol.set_list(list);

    std::string exp_ol("<ol>\n  <li>test1</li>\n  <li>test2</li>\n  <li>test3</li>\n</ol>");
    ASSERT_EQ(ol.make_html_string(), exp_ol);

    ol.list_append("test4");

    exp_ol = ("<ol>\n  <li>test1</li>\n  <li>test2</li>\n  <li>test3</li>\n  <li>test4</li>\n</ol>");
    ASSERT_EQ(ol.make_html_string(), exp_ol);

    ol.list_remove(1);

    exp_ol = ("<ol>\n  <li>test1</li>\n  <li>test3</li>\n  <li>test4</li>\n</ol>");
    ASSERT_EQ(ol.make_html_string(), exp_ol);
}

TEST(Ul, init) {
    Ul ul{};
    std::string pure_ul("<ul></ul>");
    EXPECT_EQ(ul.make_html_string(), pure_ul);
}

TEST(Ul, set_list) {
    Ul ul{};

    std::vector<std::string> list = {"test1", "test2", "test3"};

    ul.set_list(list);

    std::string exp_ul("<ul>\n  <li>test1</li>\n  <li>test2</li>\n  <li>test3</li>\n</ul>");
    ASSERT_EQ(ul.make_html_string(), exp_ul);

    ul.list_append("test4");

    exp_ul = ("<ul>\n  <li>test1</li>\n  <li>test2</li>\n  <li>test3</li>\n  <li>test4</li>\n</ul>");
    ASSERT_EQ(ul.make_html_string(), exp_ul);

    ul.list_remove(1);

    exp_ul = ("<ul>\n  <li>test1</li>\n  <li>test3</li>\n  <li>test4</li>\n</ul>");
    ASSERT_EQ(ul.make_html_string(), exp_ul);
}

TEST(Select, init) {
    Select select{};
    std::string pure_select("<select></select");
    EXPECT_EQ(select.make_html_string(), pure_select);
}

TEST(Select, set_list) {
    Select select{};

    std::vector<std::string> list = {"test1", "test2", "test3"};

    select.set_list(list);

    std::string exp_select("<select>\n  <option>test1</option>\n  <option>test2</option>\n  <option>test3</option>\n</select>");
    ASSERT_EQ(select.make_html_string(), exp_select);

    select.list_append("test4");

    exp_select = ("<select>\n  <option>test1</option>\n  <option>test2</option>\n  <option>test3</option>\n  <option>test4</option>\n</select>");
    ASSERT_EQ(select.make_html_string(), exp_select);

    select.list_remove(1);

    exp_select = ("<select>\n  <option>test1</option>\n  <option>test3</option>\n  <option>test4</option>\n</select>");
    ASSERT_EQ(select.make_html_string(), exp_select);
}

TEST(Select, set_attributes) {
    Select select{};

    select.set_multiple(5);
    select.set_size(10);
    select.set_required(true);
    select.list_append("test1");

    std::string exp_select("<select size=\"10\" multiple = \"5\" required>\n  <option>test</option>\n</select>");

    EXPECT_EQ(select.make_html_string(), exp_select);
}
