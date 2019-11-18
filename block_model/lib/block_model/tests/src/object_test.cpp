#include "a.h"
#include "div.h"
#include "img.h"
#include "gtest/gtest.h"

TEST(A, init) {
    A a{};
    std::string pure_link("<a href=\"\"></a>");
    EXPECT_EQ(a.make_html_string(), pure_link);
}

TEST(A, set_link) {
    A a{};
    std::string href("path");
    std::string content("link");

    a.set_href(href);
    a.set_tag_content(content);

    std::string exp_link(R"(<a href="path">link</a>)");
    EXPECT_EQ(a.make_html_string(), exp_link);
}

TEST(A, set_anchor) {
    A a{};
    std::string name("anchor");
    std::string content("link");

    a.set_id(name);
    a.set_tag_content(content);

    std::string exp_link(R"(<a id="anchor">link</a>)");
    EXPECT_EQ(a.make_html_string(), exp_link);
}

TEST(Img, init) {
    Img img{};
    std::string pure_img("<img src=\"\">");
    EXPECT_EQ(img.make_html_string(), pure_img);
}

TEST(Img, set_attributes) {
    Img img{};
    std::string src("path");
    int width = 50;
    int height = 100;

    img.set_src(src);
    img.set_width(width);
    img.set_height(height);

    std::string std_img(R"(<img src="path" width="50" height="100">)");
    EXPECT_EQ(img.make_html_string(), std_img);
}

TEST(Any_object, global_attributes) {
    Div div{};

    div.set_class("class");
    div.set_hidden(true);
    div.set_id("name");
    div.set_tag_content("content");
    div.set_title("title");

    std::string exp_div(R"(<div id="name" title="title" class="class" hidden="true">content</div>)");
    EXPECT_EQ(div.make_html_string(), exp_div);
}
