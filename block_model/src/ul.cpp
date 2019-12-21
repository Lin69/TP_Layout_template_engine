#include <block_model/ul.h>

block_model::Ul::Ul() = default;

block_model::Ul::Ul(const block_model::Ul& src) = default;

block_model::Ul::Ul(block_model::Ul&& src) noexcept : Object(std::move(src)) {
  list_content.vec = std::move(src.list_content.vec);
}

block_model::Ul& block_model::Ul::operator=(const block_model::Ul& src) {
  if (this == &src) {
    return *this;
  }

  CopyAttributes(src);
  list_content.vec = src.list_content.vec;

  return *this;
}

block_model::Ul::~Ul() = default;

void block_model::Ul::SetTagContent(const block_model::String& new_content) {}

block_model::Map block_model::Ul::MakeHtmlString() const {
  Map result;

  result.set_tag(String("ul"));
  result.set_end();
  CheckAttributes(result);

  String list("\n");
  for (const auto& it : list_content.vec) {
    list + String("\t<li>") + it + String("</li>\n");
  }
  result.insert(list);

  return result;
}
