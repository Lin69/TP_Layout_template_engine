#include <block_model/input.h>

block_model::Input::Input() : type_attr(submit) {}

block_model::Input::Input(const block_model::Input& src) = default;

block_model::Input::Input(block_model::Input&& src) noexcept
    : Object(std::move(src)),
      type_attr(src.type_attr),
      value_attr(std::move(src.value_attr)) {
  tag_content.str = std::move(src.tag_content.str);
  class_attr.vec = std::move(src.class_attr.vec);
  hidden = src.hidden;
  title.str = std::move(src.title.str);

  form_ptr = std::move(src.form_ptr);
}

block_model::Input& block_model::Input::operator=(
    const block_model::Input& src) {
  if (this == &src) {
    return *this;
  }

  CopyAttributes(src);
  form_ptr = src.form_ptr;
  type_attr = src.type_attr;
  value_attr.str = src.value_attr.str;

  return *this;
}

block_model::Input::~Input() = default;

void block_model::Input::SetType(const block_model::object_type& type) {
  type_attr = type;
}

void block_model::Input::SetValue(const block_model::String& new_value) {
  value_attr.str = new_value.str;
}

block_model::Map block_model::Input::MakeHtmlString() const {
  Map result;

  result.set_tag(String("input"));
  result.set_end(false);
  CheckAttributes(result);

  result.insert(String("type"), type_array[type_attr]);
  result.insert(String("value"), value_attr);
  result.insert(String("form"), String(form_ptr->GetId()));

  return result;
}
