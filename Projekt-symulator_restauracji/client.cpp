#include "client.hpp"
#include <chrono>
#include <thread>
#include <random>

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
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> menu_section_distribution(0, menu.get_menu_sections().size() - 1);
    std::uniform_int_distribution<> menu_item_distribution(0, menu.get_menu_sections().begin()->get_menu_items().size() - 1);
    auto menu_section_it = menu.get_menu_sections().begin();
    std::advance(menu_section_it, menu_section_distribution(gen));
    auto menu_item_it = menu_section_it->get_menu_items().begin();
    std::advance(menu_item_it, menu_item_distribution(gen));
    MenuItem menu_item = menu_item_it->second;

    chosen_dishes.push_back(menu_item);
    switch_flag(is_ready_to_order);
}

std::vector<MenuItem> Client::get_chosen_dishes() const
{
    return chosen_dishes;
}

void Client::eating()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    switch_flag(is_ready_to_pay);
}
