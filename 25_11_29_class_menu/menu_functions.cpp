#include <cstdlib>
#include <iostream>

#include "menu_functions.hpp"
#include "menu.hpp"

const TTagilceva::MenuItem* TTagilceva::show_menu(const MenuItem* current) {
    if (current->greeting) {
        std::cout << current->greeting << std::endl;
    } else {
        std::cout << current->title << std::endl;
    }
    std::cout << std::endl;

    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }

    std::cout << current->children[0]->title << std::endl;
    std::cout << "Ваш выбор > ";

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    if (user_input >= 0 && user_input < current->children_count) {
        return current->children[user_input];
    } else {
        std::cout << "Неверный выбор, попробуйте снова." << std::endl;
        return current;
    }
}

const TTagilceva::MenuItem* TTagilceva::exit(const MenuItem* current) {
    std::exit(0);
}

const TTagilceva::MenuItem* TTagilceva::go_back(const MenuItem* current) {
    if (current->parent) {
        return current->parent;
    }
    return current;
}
const TTagilceva::MenuItem* TTagilceva::show_spbu(const MenuItem* current) {
    return TTagilceva::show_menu(current);
}
/*const TTagilceva::MenuItem* TTagilceva::show_spbu(const MenuItem* current) {
    std::cout << "Вы выбрали СПБГУ" << std::endl;
    return current;
}*/
const TTagilceva::MenuItem* TTagilceva::show_pm_pu(const MenuItem* current) {
    std::cout << "Факультет Прикладной математики - Процессов Управления" << std::endl;
    std::cout << std::endl;
    return current->parent;
}
const TTagilceva::MenuItem* TTagilceva::show_matmech(const MenuItem* current) {
    std::cout << "Математика-механический факультет" << std::endl;
    std::cout << std::endl;
    return current->parent;
}
const TTagilceva::MenuItem* TTagilceva::show_linguistics(const MenuItem* current) {
    std::cout << "Лингвистический факультет" << std::endl;
    std::cout << std::endl;
    return current->parent;
}
const TTagilceva::MenuItem* TTagilceva::back_to_universities(const MenuItem* current) {
    return current->parent->parent;
}
const TTagilceva::MenuItem* TTagilceva::show_itmo(const MenuItem* current) {
    std::cout << "Вы выбрали ИТМО" << std::endl;
    return current->parent;
}

const TTagilceva::MenuItem* TTagilceva::show_polytech(const MenuItem* current) {
    std::cout << "Вы выбрали Политех" << std::endl;
    return current->parent;
}

const TTagilceva::MenuItem* TTagilceva::show_leti(const MenuItem* current) {
    std::cout << "Вы выбрали ЛЭТИ" << std::endl;
    return current->parent;
}

const TTagilceva::MenuItem* TTagilceva::back_to_main(const MenuItem* current) {
    return current->parent->parent;
}
