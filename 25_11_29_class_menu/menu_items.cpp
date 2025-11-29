#include <cstddef>

#include "menu_items.hpp"
#include "menu_functions.hpp"

namespace {
    const TTagilceva::MenuItem* const main_children[] = {
        &TTagilceva::EXIT,
        &TTagilceva::UNIVERSITES,
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
    const char* main_greeting = "Главное меню";
}

const TTagilceva::MenuItem TTagilceva::MAIN = {
    "Главное меню",
    TTagilceva::show_menu,
    nullptr,
    main_greeting,
    main_children,
    main_size
};

namespace {
    const TTagilceva::MenuItem* const universities_children[] = {
        &TTagilceva::BACK_TO_MAIN,
        &TTagilceva::SPBU,
        &TTagilceva::ITMO,
        &TTagilceva::POLYTECH,
        &TTagilceva::LETI
    };
    const int universities_size = sizeof(universities_children) / sizeof(universities_children[0]);
    const char* universities_greeting = "Вузы Санкт-Петербурга";
}

const TTagilceva::MenuItem TTagilceva::UNIVERSITES = {
    "1 - Хочу посмотреть вузы Санкт-Петербурга",
    TTagilceva::show_menu,
    &TTagilceva::MAIN,
    universities_greeting,
    universities_children,
    universities_size
};

const TTagilceva::MenuItem TTagilceva::EXIT = {
    "0 - Я уже студент",
    TTagilceva::exit,
    &TTagilceva::MAIN,
    nullptr,
    nullptr,
    0
};

const TTagilceva::MenuItem TTagilceva::SPBU = {
    "1 - СПбГУ",
    TTagilceva::show_menu,
    &TTagilceva::UNIVERSITES,
    "Санкт-Петербургский государственный университет",
    nullptr,
    0
};

const TTagilceva::MenuItem TTagilceva::ITMO = {
    "2 - ИТМО",
    TTagilceva::show_menu,
    &TTagilceva::UNIVERSITES,
    "Университет ИТМО",
    nullptr,
    0
};

const TTagilceva::MenuItem TTagilceva::POLYTECH = {
    "3 - Политех",
    TTagilceva::show_menu,
    &TTagilceva::UNIVERSITES,
    "Санкт-Петербургский политехнический университет",
    nullptr,
    0
};

const TTagilceva::MenuItem TTagilceva::LETI = {
    "4 - ЛЭТИ",
    TTagilceva::show_menu,
    &TTagilceva::UNIVERSITES,
    "Санкт-Петербургский государственный электротехнический университет",
    nullptr,
    0
};

const TTagilceva::MenuItem TTagilceva::BACK_TO_MAIN = {
    "0 - Назад в главное меню",
    TTagilceva::go_back,
    &TTagilceva::UNIVERSITES,
    nullptr,
    nullptr,
    0
};
