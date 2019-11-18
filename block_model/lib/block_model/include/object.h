#ifndef TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H
#define TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H

#include <string>
#include <vector>
#include <memory>

// Обобщающий класс Object, содержащий глобальные атрибуты
class Object {
public:
    virtual std::string make_html_string() = 0;

    void set_tag_content(const std::string& new_content);
    void set_id(const std::string& new_id);
    void set_class(const std::string& new_class);
    void set_class(const std::vector<std::string>& new_class);
    void set_hidden(const bool& value);
    void set_title(const std::string& new_title);

protected:
    std::string tag_content;
    std::string id_attr;
    std::vector<std::string> class_attr;
    bool hidden;
    std::string title;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H
