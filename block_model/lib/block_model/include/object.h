#ifndef TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H
#define TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H

#include <array>
#include <list>
#include <memory>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

namespace block_model {
    class Object;

    struct String {
        String() = default;
        String(const String&) = default;
        explicit String(std::string str) : str(std::move(str)) {};
        explicit String(int str) : str(std::to_string(str)) {};
        [[nodiscard]] bool is_empty() const {
            return str.empty();
        };
        String& operator+(const String& src) {
            this->str = this->str + src.str;
            return *this;
        };
        bool operator==(const String& src) {
            return this->str == src.str;
        }
        std::string str;
    };

    const String object_template("%%%Object%%%: ");

    template <typename T>
    struct Vector {
        Vector() = default;
        explicit Vector(std::vector<T> vec) : vec(std::move(vec)) {};
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

        void insert(const String& value) {
            content.push_back(value);
        }

        void set_tag(const String& value) {
            tag = value;
        };

        void set_end(bool value = true) {
            end_tag = value;
        };

        String tag;
        bool end_tag = true;

        std::vector<String> content;

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
        void SetClass(const Vector<String>& new_class);
        void SetHidden(bool value);
        void SetTitle(const String& new_title);

        [[nodiscard]] int GetId() const;

        virtual ~Object();

    protected:
        void CheckAttributes(Map& result) const;

        void CopyAttributes(const Object& src);

        static int id_count; // Каждому объекту присваивается уникальный id с 0 до n
        int id_attr{}; // При этом при уничтожении объекта последующие id не уменьшаются

        String tag_content;
        Vector<String> class_attr;
        bool hidden;
        String title;
    };
}
#endif //TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H
