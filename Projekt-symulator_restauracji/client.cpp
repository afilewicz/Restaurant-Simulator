#include "client.hpp"

Client::Client() {}

bool &Client::get_is_ready_to_order()
{
    return is_ready_to_order;
}

bool &Client::get_is_ready_to_pay()
{
    return is_ready_to_pay;
}

void Client::switch_flag(bool &flag)
{
    flag = !flag;
}

void Client::make_order(Menu &menu)
{
    MenuItem menu_item = menu.get_menu_section_by_name("Przystawki")->get_menu_item_by_name("Chipsy z sosem");
    chosen_dishes.push_back(menu_item);
    switch_flag(is_ready_to_order);
}

std::vector<MenuItem> Client::get_chosen_dishes() const
{
    return chosen_dishes;
}
