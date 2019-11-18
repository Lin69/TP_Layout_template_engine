#include "a.h"
#include "div.h"
#include "img.h"
#include "gtest/gtest.h"

TEST(A, init) {
    A a{};
    std::string pure_link("<a href=\"\"></a>");
    EXPECT_EQ(a.MakeHtmlString(), pure_link);
}

TEST(A, set_link) {
    A a{};
    std::string href("path");
    std::string content("link");

    a.SetHref(href);
    a.SetTagContent(content);

    std::string exp_link(R"(<a href="path">link</a>)");
    EXPECT_EQ(a.MakeHtmlString(), exp_link);
}

TEST(A, set_anchor) {
    A a{};
    std::string name("anchor");
    std::string content("link");

    a.SetId(name);
    a.SetTagContent(content);

    std::string exp_link(R"(<a id="anchor">link</a>)");
    EXPECT_EQ(a.MakeHtmlString(), exp_link);
}

TEST(Img, init) {
    Img img{};
    std::string pure_img("<img src=\"\">");
    EXPECT_EQ(img.MakeHtmlString(), pure_img);
}

TEST(Img, set_attributes) {
    Img img{};
    std::string src("path");
    int width = 50;
    int height = 100;

    img.SetSrc(src);
    img.SetWidth(width);
    img.SetHeight(height);

    std::string std_img(R"(<img src="path" width="50" height="100">)");
    EXPECT_EQ(img.MakeHtmlString(), std_img);
}

TEST(Any_object, global_attributes) {
    Div div{};

    div.SetClass("class");
    div.SetHidden(true);
    div.SetId("name");
    div.SetTagContent("content");
    div.SetTitle("title");

    std::string exp_div(R"(<div id="name" title="title" class="class" hidden="true">content</div>)");
    EXPECT_EQ(div.MakeHtmlString(), exp_div);
}
