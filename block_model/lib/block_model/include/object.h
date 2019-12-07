#ifndef TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H
#define TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H

#include <string>
#include <vector>
#include <memory>

namespace block_model {
    struct string {
        string() = default;
        explicit string(std::string str) : str(std::move(str)) {};
        explicit string(int str) : str(std::to_string(str)) {};
        [[nodiscard]] bool is_empty() const {
            return str.empty();
        }
        void operator+(const string& src) {
            this->str = this->str + src.str;
        };
        std::string str;
    };

    template <typename T>
    struct vector {
        vector () = default;
        explicit vector(std::vector<T> vec) : vec(std::move(vec)) {};
        [[nodiscard]] bool is_empty() const {
            return vec.empty();
        };
        std::vector<T> vec;
    };

// Обобщающий класс Object, содержащий глобальные атрибуты
    class Object {
    public:
        Object();

        [[nodiscard]] virtual string MakeHtmlString() const = 0;

        virtual void SetTagContent(const string &new_content);
        void SetClass(const string& new_class);
        void SetClass(const vector<string>& new_class);
        void SetHidden(const bool& value);
        void SetTitle(const string& new_title);

        virtual ~Object();

    protected:
        void CheckAttributes(string& result) const;
        void WrapAttribute(string& result, const string& attribute, const string& value) const;
        void WrapAttribute(string& result, const string& attribute, const int& value) const;

        static int id_count; // Каждому объекту присваивается уникальный id с 0 до n
        int id_attr; // При этом при уничтожении объекта последующие id не уменьшаются

        string tag_content;
        vector<string> class_attr;
        bool hidden;
        string title;
    };
}
#endif //TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H
