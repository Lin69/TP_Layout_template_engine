#include "Button.h"
#include "gtest/gtest.h"
#include "Textarea.h"
#include "Input.h"

TEST(Button, init) {
    Button button{};
    std::string pure_button("<button></button>");
    EXPECT_EQ(button.make_html_string(), pure_button);
}

TEST(Input, init) {
    Input input{};
    std::string pure_input("<input type=\"radio\">");
    EXPECT_EQ(input.make_html_string(), pure_input);
}

TEST(Input, set_attributes) {
    Input input{};

    _type test_type = image;
    
    input.set_type(test_type);
    input.set_value("string");

    std::string exp_input(R"(<input type="image" value="string")");
    EXPECT_EQ(input.make_html_string(), exp_input);
}

TEST(Textarea, init) {
    Textarea textarea{};
    std::string pure_textarea("<textarea></textarea>");
    EXPECT_EQ(textarea.make_html_string(), pure_textarea);
}

TEST(Textarea, set_attributes) {
    Textarea textarea{};

    textarea.set_cols(10);
    textarea.set_rows(20);
    textarea.set_maxlength(50);
    textarea.set_placeholder("text");
    textarea.set_readonly(true);
    textarea.set_required(true);

    std::string exp_textarea(R"(<textarea rows="20" cols="10" maxlength="50" placeholder="text" readonly required></textarea>)");
    EXPECT_EQ(textarea.make_html_string(), exp_textarea);
}
