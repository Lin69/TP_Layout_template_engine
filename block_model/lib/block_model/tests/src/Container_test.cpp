#include "Form.h"
#include "Div.h"
#include "gtest/gtest.h"

TEST(Form, init) {
    Form form{};
    std::string pure_form("<form></form>");
    EXPECT_EQ(form.make_html_string(), pure_form);
}

TEST(Form, container) {

}

TEST(Form, set_attributes) {
    Form form{};

    form.set_action("action");
    form.set_http_method(true);

    std::string exp_form(R"(<form action="action" method="post"></form>)");
    EXPECT_EQ(form.make_html_string(), exp_form);
}

TEST(Div, init) {
    Div div{};
    std::string pure_div("<div></div>");
    EXPECT_EQ(div.make_html_string(), pure_div);
}

TEST(Div, container) {

}
