#include "form.h"
#include "div.h"
#include "gtest/gtest.h"

TEST(Form, init) {
    Form form{};
    std::string pure_form("<form></form>");
    EXPECT_EQ(form.MakeHtmlString(), pure_form);
}

TEST(Form, container) {

}

TEST(Form, set_attributes) {
    Form form{};

    form.SetAction("action");
    form.SetHttpMethod(true);

    std::string exp_form(R"(<form action="action" method="post"></form>)");
    EXPECT_EQ(form.MakeHtmlString(), exp_form);
}

TEST(Div, init) {
    Div div{};
    std::string pure_div("<div></div>");
    EXPECT_EQ(div.MakeHtmlString(), pure_div);
}

TEST(Div, container) {

}
