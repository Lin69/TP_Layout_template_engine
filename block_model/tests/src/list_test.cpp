#include "block_model/ol.h"
#include "block_model/select.h"
#include "block_model/ul.h"
#include "gtest/gtest.h"

using namespace block_model;

/*TEST(Ol, init) {
    Ol ol;
    std::string pure_ol("<ol id=\"5\">\n</ol>");
    EXPECT_EQ(ol.MakeHtmlString().str, pure_ol);
}

TEST(Ol, set_list) {
    Ol ol;

    std::vector<String> list = {block_model::String("test1"),
block_model::String("test2"), block_model::String("test3")}; Vector<String>
list_wrap(list);

    ol.SetList(list_wrap);

    std::string exp_ol("<ol
id=\"6\">\n\t<li>test1</li>\n\t<li>test2</li>\n\t<li>test3</li>\n</ol>");
    ASSERT_EQ(ol.MakeHtmlString().str, exp_ol);

    ol.ListAppend(block_model::String("test4"));

    exp_ol = ("<ol
id=\"6\">\n\t<li>test1</li>\n\t<li>test2</li>\n\t<li>test3</li>\n\t<li>test4</li>\n</ol>");
    ASSERT_EQ(ol.MakeHtmlString().str, exp_ol);

    ol.ListRemove(1);

    exp_ol = ("<ol
id=\"6\">\n\t<li>test1</li>\n\t<li>test3</li>\n\t<li>test4</li>\n</ol>");
    ASSERT_EQ(ol.MakeHtmlString().str, exp_ol);
}

TEST(Ul, init) {
    Ul ul;
    std::string pure_ul("<ul id=\"7\">\n</ul>");
    EXPECT_EQ(ul.MakeHtmlString().str, pure_ul);
}

TEST(Ul, set_list) {
    Ul ul{};

    std::vector<String> list = {block_model::String("test1"),
block_model::String("test2"), block_model::String("test3")}; Vector<String>
list_wrap(list);

    ul.SetList(list_wrap);

    std::string exp_ul("<ul
id=\"8\">\n\t<li>test1</li>\n\t<li>test2</li>\n\t<li>test3</li>\n</ul>");
    ASSERT_EQ(ul.MakeHtmlString().str, exp_ul);

    ul.ListAppend(block_model::String("test4"));

    exp_ul = ("<ul
id=\"8\">\n\t<li>test1</li>\n\t<li>test2</li>\n\t<li>test3</li>\n\t<li>test4</li>\n</ul>");
    ASSERT_EQ(ul.MakeHtmlString().str, exp_ul);

    ul.ListRemove(1);

    exp_ul = ("<ul
id=\"8\">\n\t<li>test1</li>\n\t<li>test3</li>\n\t<li>test4</li>\n</ul>");
    ASSERT_EQ(ul.MakeHtmlString().str, exp_ul);
}

TEST(Select, init) {
    Select select;
    std::string pure_select("<select id=\"9\">\n</select>");
    EXPECT_EQ(select.MakeHtmlString().str, pure_select);
}

TEST(Select, set_list) {
    Select select{};

    std::vector<String> list = {block_model::String("test1"),
block_model::String("test2"), block_model::String("test3")}; Vector<String>
list_wrap(list);

    select.SetList(list_wrap);

    std::string exp_select("<select
id=\"10\">\n\t<option>test1</option>\n\t<option>test2</option>\n\t<option>test3</option>\n</select>");
    ASSERT_EQ(select.MakeHtmlString().str, exp_select);

    select.ListAppend(block_model::String("test4"));

    exp_select = ("<select
id=\"10\">\n\t<option>test1</option>\n\t<option>test2</option>\n\t<option>test3</option>\n\t<option>test4</option>\n</select>");
    ASSERT_EQ(select.MakeHtmlString().str, exp_select);

    select.ListRemove(1);

    exp_select = ("<select
id=\"10\">\n\t<option>test1</option>\n\t<option>test3</option>\n\t<option>test4</option>\n</select>");
    ASSERT_EQ(select.MakeHtmlString().str, exp_select);
}

TEST(Select, set_attributes) {
    Select select{};

    select.SetMultiple(true);
    select.SetSize(10);
    select.SetRequired(true);
    select.ListAppend(block_model::String("test"));

    std::string exp_select("<select multiple required size=\"10\"
id=\"11\">\n\t<option>test</option>\n</select>");

    EXPECT_EQ(select.MakeHtmlString().str, exp_select);
}*/
