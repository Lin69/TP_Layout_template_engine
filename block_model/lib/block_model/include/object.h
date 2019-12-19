#ifndef TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H
#define TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

namespace block_model {
    struct String {
        String() = default;
        explicit String(std::string str) : str(std::move(str)) {};
        explicit String(int str) : str(std::to_string(str)) {};
        [[nodiscard]] bool is_empty() const {
            return str.empty();
        }
        void operator+(const String& src) {
            this->str = this->str + src.str;
        };
        std::string str;
    };

    template <typename T>
    struct vector {
        vector() = default;
        explicit vector(std::vector<T> vec) : vec(std::move(vec)) {};
        [[nodiscard]] bool is_empty() const {
            return vec.empty();
        };
        std::vector<T> vec;
    };

    struct Map {
        Map() = default;

        void insert(const String& key, const String& value) {
            map.insert({key.str, value.str});
        };

        std::unordered_multimap<std::string, std::string> map;
    };

// Обобщающий класс Object, содержащий глобальные атрибуты
    class Object {
    public:
        Object();
        Object(const Object& src);
        Object(Object&& src) noexcept;

        [[nodiscard]] virtual Map MakeHtmlString() const = 0;

        virtual void SetTagContent(const String &new_content);
        void SetClass(const String& new_class);
        void SetClass(const vector<String>& new_class);
        void SetHidden(const bool& value);
        void SetTitle(const String& new_title);

        virtual ~Object();

    protected:
        void CheckAttributes(String& result) const;
        void WrapAttribute(String& result, const String& attribute, const String& value) const;
        void WrapAttribute(String& result, const String& attribute, const int& value) const;

        void CopyAttributes(const Object& src);

        static int id_count; // Каждому объекту присваивается уникальный id с 0 до n
        int id_attr{}; // При этом при уничтожении объекта последующие id не уменьшаются

        String tag_content;
        vector<String> class_attr;
        bool hidden;
        String title;
    };
}
#endif //TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H
