#ifndef PROJECT_PRESENTER_H
#define PROJECT_PRESENTER_H

#include <iostream>
#include <boost/spirit/include/classic.hpp>
#include <boost/spirit/include/qi.hpp>

using namespace boost::spirit;

class Presenter {
public:
    Presenter() = default;

    void run();

private:
    // TODO: синглтон

    template <typename T>
    void add() {
        // TODO: придумать решение элегентнее/переделать архитектуру
    };

    void remove(const int& id) {
        // TODO: Implementation
        // Ищем в дереве
    };

    void set(const int& id, const std::string& action) {
        // TODO: Implementation

    };

    void move(const int& id, bool direction) {
        // TODO: Implementation

        std::cout << id;
        std::cout << std::boolalpha << direction;
    };

    std::map<int, std::string> types;

    std::map<int, std::shared_ptr<block_model::A>> links;
    std::map<int, std::shared_ptr<block_model::Button>> buttons;
    std::map<int, std::shared_ptr<block_model::Div>> divs;
    std::map<int, std::shared_ptr<block_model::Form>> forms;
    std::map<int, std::shared_ptr<block_model::Img>> images;
    std::map<int, std::shared_ptr<block_model::Input>> inputs;
    std::map<int, std::shared_ptr<block_model::Ol>> ols;
    std::map<int, std::shared_ptr<block_model::Select>> selects;
    std::map<int, std::shared_ptr<block_model::Textarea>> textareas;
    std::map<int, std::shared_ptr<block_model::Ul>> uls;
};

template<>
void Presenter::add<block_model::A>() {
    auto block_pair = block_model::Create<block_model::A>();
    // Складывается в дерево

    auto id = block_pair.first->GetId();
    types.insert({id, block_pair.first->MakeHtmlString().tag.str});
    links.insert({id, block_pair.second});
}

template<>
void Presenter::add<block_model::Button>() {
    auto block_pair = block_model::Create<block_model::Button>();
    // Складывается в дерево

    auto id = block_pair.first->GetId();
    types.insert({id, block_pair.first->MakeHtmlString().tag.str});
    buttons.insert({id, block_pair.second});
};

template<>
void Presenter::add<block_model::Div>() {
    auto block_pair = block_model::Create<block_model::Div>();
    // Складывается в дерево

    auto id = block_pair.first->GetId();
    types.insert({id, block_pair.first->MakeHtmlString().tag.str});
    divs.insert({id, block_pair.second});
};

template<>
void Presenter::add<block_model::Form>() {
    auto block_pair = block_model::Create<block_model::Form>();
    // Складывается в дерево

    auto id = block_pair.first->GetId();
    types.insert({id, block_pair.first->MakeHtmlString().tag.str});
    forms.insert({id, block_pair.second});
};

template<>
void Presenter::add<block_model::Img>() {
    auto block_pair = block_model::Create<block_model::Img>();
    // Складывается в дерево

    auto id = block_pair.first->GetId();
    types.insert({id, block_pair.first->MakeHtmlString().tag.str});
    images.insert({id, block_pair.second});
};

template<>
void Presenter::add<block_model::Input>() {
    auto block_pair = block_model::Create<block_model::Input>();
    // Складывается в дерево

    auto id = block_pair.first->GetId();
    types.insert({id, block_pair.first->MakeHtmlString().tag.str});
    inputs.insert({id, block_pair.second});
};

template<>
void Presenter::add<block_model::Ol>() {
    auto block_pair = block_model::Create<block_model::Ol>();
    // Складывается в дерево

    auto id = block_pair.first->GetId();
    types.insert({id, block_pair.first->MakeHtmlString().tag.str});
    ols.insert({id, block_pair.second});
};

template<>
void Presenter::add<block_model::Select>() {
    auto block_pair = block_model::Create<block_model::Select>();
    // Складывается в дерево

    auto id = block_pair.first->GetId();
    types.insert({id, block_pair.first->MakeHtmlString().tag.str});
    selects.insert({id, block_pair.second});
};

template<>
void Presenter::add<block_model::Textarea>() {
    auto block_pair = block_model::Create<block_model::Textarea>();
    // Складывается в дерево

    auto id = block_pair.first->GetId();
    types.insert({id, block_pair.first->MakeHtmlString().tag.str});
    textareas.insert({id, block_pair.second});
};

template<>
void Presenter::add<block_model::Ul>() {
    auto block_pair = block_model::Create<block_model::Ul>();
    // Складывается в дерево

    auto id = block_pair.first->GetId();
    types.insert({id, block_pair.first->MakeHtmlString().tag.str});
    uls.insert({id, block_pair.second});
};

void Presenter::run() {
    bool work = true;

    int forward_id = 0;
    bool direction;

    std::string action;
    auto iterator = action.begin();

    qi::rule<std::string::iterator> actions = (
                                                      qi::lit("add") >> ascii::space >> (
                                                              qi::lit("a")[([&](){add<block_model::A>();})] |
                                                              qi::lit("button")[([&](){add<block_model::Button>();})] |
                                                              qi::lit("div")[([&](){add<block_model::Div>();})] |
                                                              qi::lit("form")[([&](){add<block_model::Form>();})] |
                                                              qi::lit("img")[([&](){add<block_model::Img>();})] |
                                                              qi::lit("input")[([&](){add<block_model::Input>();})] |
                                                              qi::lit("ol")[([&](){add<block_model::Ol>();})] |
                                                              qi::lit("select")[([&](){add<block_model::Select>();})] |
                                                              qi::lit("textarea")[([&](){add<block_model::Textarea>();})] |
                                                              qi::lit("ul")[([&](){add<block_model::Ul>();})]
                                                      )
                                              ) | (
                                                      qi::lit("remove") >> ascii::space >>
                                                                        qi::int_[([&](const int& id){remove(id);})]
                                              ) | (
                                                      qi::lit("move") >> ascii::space >>
                                                                      qi::int_[([&](const int& id){forward_id = id;})] >> ascii::space >> (
                                                                              qi::lit("up")[([&](){direction = true;})] |
                                                                              qi::lit("down")[([&](){direction = false;})]
                                                                      )[([&](){move(forward_id, direction);})]
                                              )[([&](){std::cout << std::endl;})] | (
                                                      qi::lit("set") >> ascii::space >>
                                                                     qi::int_[([&](const int& id){forward_id = id;})] >> ascii::space
                                              )[([&](){set(forward_id, iterator.base());})] | (
                                                      qi::lit("exit") | qi::lit("quit") | qi::lit("q")
                                              )[([&](){work = false;})];

    while (work) {
        std::getline(std::cin, action);
        iterator = action.begin();

        qi::phrase_parse(iterator, action.end(), actions, ascii::space);
        std::cout << std::endl;
    }
}

#endif //PROJECT_PRESENTER_H
