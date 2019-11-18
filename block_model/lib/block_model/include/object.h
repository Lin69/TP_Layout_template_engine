#ifndef TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H
#define TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H

#include <string>
#include <vector>
#include <memory>

// Обобщающий класс Object, содержащий глобальные атрибуты
class Object {
public:
    virtual std::string MakeHtmlString() = 0;

    void SetTagContent(const std::string& new_content);
    void SetId(const std::string& new_id);
    void SetClass(const std::string& new_class);
    void SetClass(const std::vector<std::string>& new_class);
    void SetHidden(const bool& value);
    void SetTitle(const std::string& new_title);

protected:
    std::string tag_content;
    std::string id_attr;
    std::vector<std::string> class_attr;
    bool hidden;
    std::string title;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H
