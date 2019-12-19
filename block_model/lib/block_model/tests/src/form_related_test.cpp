#include "button.h"
#include "gtest/gtest.h"
#include "textarea.h"
#include "input.h"

using namespace block_model;

/*
TEST(Button, init) {
    Button button;
    std::string pure_button("<button id=\"0\"></button>");
    EXPECT_EQ(button.MakeHtmlString().str, pure_button);
}

TEST(Input, init) {
    Input input;
    std::string pure_input("<input type=\"submit\" id=\"1\">");
    EXPECT_EQ(input.MakeHtmlString().str, pure_input);
}


TEST(Input, set_attributes) {
    Input input;

    object_type test_type = image;

    input.SetType(test_type);
    input.SetValue(block_model::String("string"));

    std::string exp_input(R"(<input type="image" value="string" id="2">)");
    EXPECT_EQ(input.MakeHtmlString().str, exp_input);
}

TEST(Textarea, init) {
    Textarea textarea{};
    std::string pure_textarea("<textarea id=\"3\"></textarea>");
    EXPECT_EQ(textarea.MakeHtmlString().str, pure_textarea);
}

TEST(Textarea, set_attributes) {
    Textarea textarea{};

    textarea.SetCols(10);
    textarea.SetRows(20);
    textarea.SetMaxlength(50);
    textarea.SetPlaceholder(block_model::String("text"));
    textarea.SetReadonly(true);
    textarea.SetRequired(true);

    std::string exp_textarea(
            R"(<textarea cols="10" rows="20" maxlength="50" placeholder="text" readonly required id="4"></textarea>)");
    EXPECT_EQ(textarea.MakeHtmlString().str, exp_textarea);
}
*/
