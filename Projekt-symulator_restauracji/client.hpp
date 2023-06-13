#pragma once
#include <vector>
#include "menu.hpp"
#include "menu_section.hpp"

class MenuItem;

class Client
{
private:
    std::vector<MenuItem> chosen_dishes;
    bool is_ready_to_order = false;
    bool is_ready_to_pay = false;

public:
    Client();
    bool &get_is_ready_to_order();
    bool &get_is_ready_to_pay();
    void switch_flag(bool &flag);
    std::vector<MenuItem> get_chosen_dishes() const;
    void make_order(Menu& menu);
    void eating();
};