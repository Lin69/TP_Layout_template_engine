#include "block_model/block_model.h"
#include "block_model/creator.h"
#include "gtest/gtest.h"

using namespace block_model;

TEST(A, init) {
  auto a_pair = Create<A>();
  auto a_map = a_pair.first->MakeHtmlString();

  Map a_map_exp;
  a_map_exp.insert(String("id"), String(0));
  a_map_exp.insert(String("href"), String(""));
  a_map_exp.set_tag(String("a"));
  a_map_exp.set_end();
  a_map_exp.insert(String(""));

  for (const auto& it : a_map_exp.map) {
    EXPECT_EQ(it.first, a_map.map.find(it.first)->first);
    EXPECT_EQ(it.second, a_map.map.find(it.first)->second);
  }

  EXPECT_EQ(a_map.tag.str, "a");
  EXPECT_EQ(a_map.end_tag, true);

  EXPECT_EQ(a_map.content[0].str, "");

  a_pair.second->SetHref(String("poker"));
  a_pair.first->SetHidden(true);
  a_pair.second->SetTitle(String("lol"));
}

/*TEST(A, set_link) {
    block_model::A a;
    block_model::String href("path");
    block_model::String content("link");

    a.SetHref(href);
    a.SetTagContent(content);

    std::string exp_link(R"(<a href="path" id="13">link</a>)");
    EXPECT_EQ(a.MakeHtmlString().str, exp_link);
}

TEST(A, constructors) {
    block_model::A a;

    std::string exp_a(R"(<a href="" id="14"></a>)");
    EXPECT_EQ(a.MakeHtmlString().str, exp_a);

    block_model::String href("path");
    a.SetHref(href);
    block_model::A copy_link = a;
    std::string exp_copy(R"(<a href="path" id="15"></a>)");
    EXPECT_EQ(copy_link.MakeHtmlString().str, exp_copy);

    std::vector<block_model::A> vec;
    vec.emplace_back(block_model::A());
    std::string exp_move(R"(<a href="" id="16"></a>)");
    EXPECT_EQ(vec[0].MakeHtmlString().str, exp_move);

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
    block_model::String src("path");
    int width = 50;
    int height = 100;

    img.SetSrc(src);
    img.SetWidth(width);
    img.SetHeight(height);

    std::string std_img(R"(<img src="path" width="50" height="100" id="19">)");
    EXPECT_EQ(img.MakeHtmlString().str, std_img);

    src.str = "new_path";
    img.SetSrc(src);
    std::string new_img(R"(<img src="new_path" width="50" height="100"
id="19">)"); EXPECT_EQ(img.MakeHtmlString().str, new_img);
}

TEST(Any_object, global_attributes) {
    block_model::Div div;

    div.SetClass(block_model::String("class"));
    div.SetHidden(true);
    div.SetTagContent(block_model::String("content"));
    div.SetTitle(block_model::String("title"));

    std::string exp_div("<div id=\"20\" class=\"class\" hidden
title=\"title\">content\n</div>"); EXPECT_EQ(div.MakeHtmlString().str, exp_div);
}*/
