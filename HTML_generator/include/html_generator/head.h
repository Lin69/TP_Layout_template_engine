#ifndef TP_LAYOUT_TEMPLATE_ENGINE_HEAD_H
#define TP_LAYOUT_TEMPLATE_ENGINE_HEAD_H

#include <map>
#include <string>

struct Head {
 public:
  using ReflectionMap = std::map<std::string, const std::string*>;

 private:
  std::string title;
  std::string author;
  std::string description;
  std::string css_file_name;

  ReflectionMap reflection() const {
    return {{"title", &title},
            {"author", &author},
            {"description", &description},
            {"css_file_name", &css_file_name}};
  }

  ReflectionMap reflectionMap;

 public:
  Head() { reflectionMap = reflection(); }

  void set_title(const std::string& title) { this->title = title; }
  void set_author(const std::string& author) { this->author = author; };
  void set_description(const std::string& description) {
    this->description = description;
  };
  void set_file_name(const std::string& file_name) {
    this->css_file_name = file_name;
  };

  auto& get_title() const { return title; }
  auto& get_author() const { return author; };
  auto& get_description() const { return description; };
  auto& get_file_name() const { return css_file_name; };

  ReflectionMap::const_iterator begin() const noexcept {
    return reflectionMap.cbegin();
  }
  ReflectionMap::const_iterator end() const noexcept {
    return reflectionMap.cend();
  }
};

#endif  // TP_LAYOUT_TEMPLATE_ENGINE_HEAD_H