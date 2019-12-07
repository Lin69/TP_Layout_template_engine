#include "a.h"
#include "a_creator.h"
#include "div.h"
#include "img.h"
#include "gtest/gtest.h"

TEST(A, init) {
    block_model::A a;

    std::string pure_link_a(R"(<a href="" id="12"></a>)");

    EXPECT_EQ(a.MakeHtmlString().str, pure_link_a);
}

TEST(A, set_link) {
    block_model::A a;
    block_model::string href("path");
    block_model::string content("link");

    a.SetHref(href);
    a.SetTagContent(content);

    std::string exp_link(R"(<a href="path" id="13">link</a>)");
    EXPECT_EQ(a.MakeHtmlString().str, exp_link);
}

TEST(A, constructors) {
    block_model::A a;

    std::string exp_a(R"(<a href="" id="14"></a>)");
    EXPECT_EQ(a.MakeHtmlString().str, exp_a);

    block_model::string href("path");
    a.SetHref(href);
    block_model::A copy_link = a;
    std::string exp_copy(R"(<a href="path" id="15"></a>)");
    EXPECT_EQ(copy_link.MakeHtmlString().str, exp_copy);

    auto move_link = block_model::A(block_model::A());
    std::string exp_move(R"(<a href="" id="16"></a>)");
    EXPECT_EQ(move_link.MakeHtmlString().str, exp_move);

    block_model::A assignment_link;
    assignment_link = a;
    std::string exp_assignment(R"(<a href="path" id="17"></a>)");
    EXPECT_EQ(assignment_link.MakeHtmlString().str, exp_assignment);
}



TEST(Img, init) {
    block_model::Img img;
    std::string pure_img(R"(<img src="" id="18">)");
    EXPECT_EQ(img.MakeHtmlString().str, pure_img);
}

TEST(Img, set_attributes) {
    block_model::Img img;
    block_model::string src("path");
    int width = 50;
    int height = 100;

    img.SetSrc(src);
    img.SetWidth(width);
    img.SetHeight(height);

    std::string std_img(R"(<img src="path" width="50" height="100" id="19">)");
    EXPECT_EQ(img.MakeHtmlString().str, std_img);

    src.str = "new_path";
    img.SetSrc(src);
    std::string new_img(R"(<img src="new_path" width="50" height="100" id="19">)");
    EXPECT_EQ(img.MakeHtmlString().str, new_img);
}

TEST(Any_object, global_attributes) {
    block_model::Div div;

    div.SetClass(block_model::string("class"));
    div.SetHidden(true);
    div.SetTagContent(block_model::string("content"));
    div.SetTitle(block_model::string("title"));

    std::string exp_div("<div id=\"20\" class=\"class\" hidden title=\"title\">content\n</div>");
    EXPECT_EQ(div.MakeHtmlString().str, exp_div);
}
