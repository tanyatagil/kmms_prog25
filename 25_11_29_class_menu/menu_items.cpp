#include <cstddef>

#include "menu_items.hpp"
#include "menu_functions.hpp"

const TTagilceva::MenuItem TTagilceva::PM_PU = {
    "1 - Факультет ПМ-ПУ",
    TTagilceva::show_pm_pu,
    &TTagilceva::SPBU
};

const TTagilceva::MenuItem TTagilceva::MATMECH = {
    "2 - Факультет МатМех",
    TTagilceva::show_matmech, 
    &TTagilceva::SPBU
};

const TTagilceva::MenuItem TTagilceva::LINGUISTICS = {
    "3 - Лингвистический факультет",
    TTagilceva::show_linguistics,
    &TTagilceva::SPBU
};

const TTagilceva::MenuItem TTagilceva::BACK_TO_UNIVERSITIES = {
    "0 - Выйти в предыдущее меню",
    TTagilceva::back_to_universities,
    &TTagilceva::SPBU
};
namespace {
    const TTagilceva::MenuItem* const spbu_children[] = {
        &TTagilceva::BACK_TO_UNIVERSITIES,
        &TTagilceva::PM_PU,
        &TTagilceva::MATMECH,
        &TTagilceva::LINGUISTICS
    };
    const int spbu_size = sizeof(spbu_children) / sizeof(spbu_children[0]);
}

namespace {
    const TTagilceva::MenuItem* const main_children[] = {
        &TTagilceva::EXIT,
        &TTagilceva::UNIVERSITES
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

const TTagilceva::MenuItem TTagilceva::ITMO = {
    "2 - ИТМО",
    TTagilceva::show_itmo,
    &TTagilceva::UNIVERSITES,
    "Санкт-Петербургский национальный исследовательский университет информационных технологий, механики и оптики",
    nullptr,
    0
};

const TTagilceva::MenuItem TTagilceva::POLYTECH = {
    "3 - Политех",
    TTagilceva::show_polytech,
    &TTagilceva::UNIVERSITES,
    "Санкт-Петербургский политехнический университет Петра Великого",
    nullptr,
    0
};

const TTagilceva::MenuItem TTagilceva::LETI = {
    "4 - ЛЭТИ",
    TTagilceva::show_leti,
    &TTagilceva::UNIVERSITES,
    "Санкт-Петербургский государственный электротехнический университет",
    nullptr,
    0
};
const TTagilceva::MenuItem TTagilceva::SPBU = {
    "1 - СПбГУ",
    TTagilceva::show_spbu,
    &TTagilceva::UNIVERSITES,
    "Санкт-Петербургский государственный университет",
    spbu_children, 
    spbu_size      
};
const TTagilceva::MenuItem TTagilceva::BACK_TO_MAIN = {
    "0 - Назад в главное меню",
    TTagilceva::back_to_main, 
    &TTagilceva::UNIVERSITES,  
    nullptr,
    nullptr,
    0
};