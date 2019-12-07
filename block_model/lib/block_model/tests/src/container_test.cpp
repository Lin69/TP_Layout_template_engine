#include "form.h"
#include "div.h"
#include "gtest/gtest.h"
#include "div_creator.h"

using namespace block_model;

/*TEST(Form, init) {
    Form form;
    std::string pure_form("<form id=\"0\">\n</form>");
    EXPECT_EQ(form.MakeHtmlString().str, pure_form);
}


TEST(Form, container) {
    Form form;

    DivCreator creator;

    auto div1 = creator.Create();
    auto div2 = creator.Create();

    form.AddObject(div1);
    form.AddObject(div2);

    std::string form_content("<form id=\"1\">\n<div id=\"2\">\n</div>\n<div id=\"3\">\n</div>\n</form>");
    EXPECT_EQ(form.MakeHtmlString().str, form_content);
}

TEST(Form, set_attributes) {
    Form form;

    form.SetAction(block_model::string("action"));
    form.SetHttpMethod(true);

    std::string exp_form("<form method=\"post\" action=\"action\" id=\"4\">\n</form>");
    EXPECT_EQ(form.MakeHtmlString().str, exp_form);
}



TEST(Div, init) {
    Div div{};
    std::string pure_div("<div></div>");
    EXPECT_EQ(div.MakeHtmlString().str, pure_div);
}

TEST(Div, container) {

}*/
