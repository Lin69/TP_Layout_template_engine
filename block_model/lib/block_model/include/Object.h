#ifndef TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H
#define TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H

#include <string>
#include <memory>
#include <vector>
#include <boost/variant.hpp>

class Div;
class Form;

class Object {
public:
    virtual std::string make_html_string() = 0;

    void set_tag_content(const std::string& content);
    void set_id(const std::string& __id);
    void set_class(const std::string& __class);
    void set_hidden(const bool& _hidden);
    void set_title(const std::string& _title);
    void set_dir(const bool& __dir);
    void set_access_key(const char& _access_key);
    void set_contenteditable(const bool& _value);

protected:
    std::string tag_content;

    std::string _id;
    std::string _class;
//    std::string _style;
    bool hidden;
    std::string title;

    bool _dir;
    char access_key;
    bool contenteditable;
};

class A_link : public Object {
public:
    A_link();
    A_link(const A_link& src);
    A_link(A_link&& src) noexcept;
    A_link& operator=(const A_link& src);
    ~A_link();

    std::string make_html_string() override;

    void set_href(const std::string& _href);
    void set_name(const std::string& __name);
    void set_download(const bool& _download);

private:
    std::string href;
    std::string _name;
    bool download;
};

class Img : public Object {
public:
    Img();
    Img(const Img& src);
    Img(Img&& src) noexcept;
    Img& operator=(const Img& src);
    ~Img();

    std::string make_html_string() override;

    void set_src(const std::string& __src);
    void set_width(const int& __width);
    void set_height(const int& __height);

private:
    int _width;
    int _height;
    std::string _src;
};

class List : public Object {
public:
    void set_list(const std::vector<std::string>& __list);
    void list_append(const std::string& item);
    void list_remove(const int& id);

protected:
    std::vector<std::string> _list;
};

class Ol : public List {
public:
    Ol();
    Ol(const Ol& src);
    Ol(Ol&& src) noexcept;
    Ol& operator=(const Ol& src);
    ~Ol();

    std::string make_html_string() override;
};

class Ul : public List {
public:
    Ul();
    Ul(const Ul& src);
    Ul(Ul&& src) noexcept;
    Ul& operator=(const Ul& src);
    ~Ul();

    std::string make_html_string() override;
};

class Select : public List {
public:
    Select();
    Select(const Select& src);
    Select(Select&& src) noexcept;
    Select& operator=(const Select& src);
    ~Select();

    std::string make_html_string() override;
    void set_multiple(const int& __multiple);
    void set_size(const int& size);
    void set_required(const bool& value);

private:
    int _multiple;
    bool _required;
    int _size;
};

class Button : public Object {
public:
    Button();
    Button(const Button& src);
    Button(Button&& src) noexcept;
    Button& operator=(const Button& src);
    ~Button();

    std::string make_html_string() override;
};

class Input : public Object {
public:
    Input();
    Input(const Input& src);
    Input(Input&& src) noexcept;
    Input& operator=(const Input& src);
    ~Input();

    std::string make_html_string() override;

    void set_type(const int& __value);
    void set_value(const std::string& __value);

private:
    enum _type {button, checkbox, _file, hidden, image, password, radio, _reset, submit, _text} __type;
    std::string _value;
};

class Textarea : public Object {
public:
    Textarea();
    Textarea(const Textarea& src);
    Textarea(Textarea&& src) noexcept;
    Textarea& operator=(const Textarea& src);
    ~Textarea();

    std::string make_html_string() override;

    void set_cols(const int& _cols);
    void set_rows(const int& _rows);
    void set_maxlength(const int& _maxlength);
    void set_placeholder(const std::string& _placeholder);
    void set_readonly(const bool& value);
    void set_required(const bool& value);
    void set_wrap(const bool& value); // TODO: небулевое значение

private:
    int cols;
    int rows;
    int maxlength;
    std::string placeholder;
    bool readonly;
    bool _required;
    bool wrap;
};

class Container : public Object {
public:
    template<typename T>
    void add_object(const T& object);

    void remove_object(const int& id);

protected:
    std::vector<boost::variant<Form, Div, List, Img, A_link, Input, Textarea, Button>> _objects;
};

template<typename T>
void Container::add_object(const T &object) {

}

class Form : public Container {
public:
    Form();
    Form(const Form& src);
    Form(Form&& src) noexcept;
    Form& operator=(const Form& src);
    ~Form();

    std::string make_html_string() override;

    void set_action(const std::string& __action);
    void set_http_method(const bool& value);

private:
    std::string _action;
    bool http_method;
};

class Div : public Container {
public:
    Div();
    Div(const Div& src);
    Div(Div&& src) noexcept;
    Div& operator=(const Div& src);
    ~Div();

    std::string make_html_string() override;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H
