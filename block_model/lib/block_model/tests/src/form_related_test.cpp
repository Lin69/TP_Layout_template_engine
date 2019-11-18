#include "button.h"
#include "gtest/gtest.h"
#include "textarea.h"
#include "input.h"

TEST(Button, init) {
    Button button{};
    std::string pure_button("<button></button>");
    EXPECT_EQ(button.MakeHtmlString(), pure_button);
}

TEST(Input, init) {
    Input input{};
    std::string pure_input("<input type=\"radio\">");
    EXPECT_EQ(input.MakeHtmlString(), pure_input);
}

TEST(Input, set_attributes) {
    Input input{};

    _type test_type = image;

    input.SetType(test_type);
    input.SetValue("string");

    std::string exp_input(R"(<input type="image" value="string")");
    EXPECT_EQ(input.MakeHtmlString(), exp_input);
}

TEST(Textarea, init) {
    Textarea textarea{};
    std::string pure_textarea("<textarea></textarea>");
    EXPECT_EQ(textarea.MakeHtmlString(), pure_textarea);
}

TEST(Textarea, set_attributes) {
    Textarea textarea{};

    textarea.SetCols(10);
    textarea.SetRows(20);
    textarea.SetMaxlength(50);
    textarea.SetPlaceholder("text");
    textarea.SetReadonly(true);
    textarea.SetRequired(true);

    std::string exp_textarea(R"(<textarea rows="20" cols="10" maxlength="50" placeholder="text" readonly required></textarea>)");
    EXPECT_EQ(textarea.MakeHtmlString(), exp_textarea);
}
