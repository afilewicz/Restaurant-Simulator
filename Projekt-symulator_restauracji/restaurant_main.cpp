#include "restaurant_simulator.hpp"
#include <iostream>

int main()
{
    RestaurantSimulator simulator(Restaurant{"restaurant"});
    simulator.set_restaurant_attributes("menu.csv", "menu.csv");
    simulator.show_menu(std::cout);
};
