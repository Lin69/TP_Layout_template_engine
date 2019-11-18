#include "ol.h"
#include "ul.h"
#include "select.h"
#include "gtest/gtest.h"

TEST(Ol, init) {
    Ol ol{};
    std::string pure_ol("<ol></ol>");
    EXPECT_EQ(ol.MakeHtmlString(), pure_ol);
}

TEST(Ol, set_list) {
    Ol ol{};

    std::vector<std::string> list = {"test1", "test2", "test3"};

    ol.SetList(list);

    std::string exp_ol("<ol>\n  <li>test1</li>\n  <li>test2</li>\n  <li>test3</li>\n</ol>");
    ASSERT_EQ(ol.MakeHtmlString(), exp_ol);

    ol.ListAppend("test4");

    exp_ol = ("<ol>\n  <li>test1</li>\n  <li>test2</li>\n  <li>test3</li>\n  <li>test4</li>\n</ol>");
    ASSERT_EQ(ol.MakeHtmlString(), exp_ol);

    ol.ListRemove(1);

    exp_ol = ("<ol>\n  <li>test1</li>\n  <li>test3</li>\n  <li>test4</li>\n</ol>");
    ASSERT_EQ(ol.MakeHtmlString(), exp_ol);
}

TEST(Ul, init) {
    Ul ul{};
    std::string pure_ul("<ul></ul>");
    EXPECT_EQ(ul.MakeHtmlString(), pure_ul);
}

TEST(Ul, set_list) {
    Ul ul{};

    std::vector<std::string> list = {"test1", "test2", "test3"};

    ul.SetList(list);

    std::string exp_ul("<ul>\n  <li>test1</li>\n  <li>test2</li>\n  <li>test3</li>\n</ul>");
    ASSERT_EQ(ul.MakeHtmlString(), exp_ul);

    ul.ListAppend("test4");

    exp_ul = ("<ul>\n  <li>test1</li>\n  <li>test2</li>\n  <li>test3</li>\n  <li>test4</li>\n</ul>");
    ASSERT_EQ(ul.MakeHtmlString(), exp_ul);

    ul.ListRemove(1);

    exp_ul = ("<ul>\n  <li>test1</li>\n  <li>test3</li>\n  <li>test4</li>\n</ul>");
    ASSERT_EQ(ul.MakeHtmlString(), exp_ul);
}

TEST(Select, init) {
    Select select{};
    std::string pure_select("<select></select");
    EXPECT_EQ(select.MakeHtmlString(), pure_select);
}

TEST(Select, set_list) {
    Select select{};

    std::vector<std::string> list = {"test1", "test2", "test3"};

    select.SetList(list);

    std::string exp_select("<select>\n  <option>test1</option>\n  <option>test2</option>\n  <option>test3</option>\n</select>");
    ASSERT_EQ(select.MakeHtmlString(), exp_select);

    select.ListAppend("test4");

    exp_select = ("<select>\n  <option>test1</option>\n  <option>test2</option>\n  <option>test3</option>\n  <option>test4</option>\n</select>");
    ASSERT_EQ(select.MakeHtmlString(), exp_select);

    select.ListRemove(1);

    exp_select = ("<select>\n  <option>test1</option>\n  <option>test3</option>\n  <option>test4</option>\n</select>");
    ASSERT_EQ(select.MakeHtmlString(), exp_select);
}

TEST(Select, set_attributes) {
    Select select{};

    select.SetMultiple(5);
    select.SetSize(10);
    select.SetRequired(true);
    select.ListAppend("test1");

    std::string exp_select("<select size=\"10\" multiple = \"5\" required>\n  <option>test</option>\n</select>");

    EXPECT_EQ(select.MakeHtmlString(), exp_select);
}
