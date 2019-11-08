#ifndef TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H
#define TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H

#include <string>
#include <memory>
#include <vector>
#include <boost/variant.hpp>

class Form;

class Object {
public:
    virtual std::string make_html_string() = 0;

    virtual void set_tag_content(std::string content);
    virtual void set_id(std::string __id);
    virtual void set_class(std::string __class);
    virtual void set_hidden(bool _hidden);
    virtual void set_title(std::string _title);
    virtual void set_dir(bool __dir);
    virtual void set_access_key(char _access_key);
    virtual void set_contenteditable(bool _value);

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
    std::string make_html_string() override;

    void set_href(std::string _href);
    void set_name(std::string __name);
    void set_download(std::string _download);

private:
    std::string href;
    std::string _name;
    bool download;
};

class Img : public Object {
public:
    std::string make_html_string() override;

    void set_src(std::string __src);
    void set_width(int __width);
    void set_height(int __height);

private:
    int _width;
    int _height;
    std::string _src;
};

class List : public Object {
public:
    void set_list(std::vector<std::string>);
    void list_append(std::string);
    void list_remove(int id);

protected:
    std::vector<std::string> _list;
};

class Ol : public List {
public:
    std::string make_html_string() override;
};

class Ul : public List {
public:
    std::string make_html_string() override;
};

class Select : public List {
public:
    std::string make_html_string() override;
    void set_multiple(int __multiple);
    void set_size(int size);
    void set_required(bool value);

private:
    int _multiple;
    bool _required;
    int _size;
};

class Button : public Object {
public:
    std::string make_html_string() override;
};

class Input : public Object {
public:
    std::string make_html_string() override;

    void set_type(int __value);
    void set_value(std::string __value);
private:
    enum _type {button, checkbox, _file, hidden, image, password, radio, _reset, submit, _text} _type;
    std::string _value;
};

class Textarea : public Object {
public:
    std::string make_html_string() override;

    void set_cols(int _cols);
    void set_rows(int _rows);
    void set_maxlength(int _maxlength);
    void set_placeholder(std::string _placeholder);
    void set_readonly(bool value);
    void set_required(bool value);
    void set_wrap(bool value);

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
    void add_object(T object);

    void remove_object(int id);
};

class Form : public Container {
public:
    std::string make_html_string() override;

    void set_action(std::string __action);
    void set_http_method(bool value);

private:
    std::vector<boost::variant<List, Img, A_link, Input, Textarea, Button>> _objects;

    std::string _action;
    bool http_method;
};

class Div : public Container {
public:
    std::string make_html_string() override;

private:
    std::vector<boost::variant<Form, List, Img, A_link, Input, Textarea, Button>> _objects;
};

#endif //TP_LAYOUT_TEMPLATE_ENGINE_OBJECT_H
