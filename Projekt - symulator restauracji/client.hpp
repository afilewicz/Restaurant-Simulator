#pragma once
#include <vector>
#include "menuitem.hpp"

class Client
{
    private:
        std::vector<MenuItem> chosen_dishes;
        bool is_ready_to_order = false;
        bool is_ready_to_pay = false;
    public:
        Client();
        bool get_is_ready_to_order() const;
        void switch_is_ready_to_order();
        bool get_is_ready_to_pay() const;
        void switch_is_ready_to_pay();
        std::vector<MenuItem> get_chosen_dishes();
        void eating();
};