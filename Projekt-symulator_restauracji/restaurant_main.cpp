#include "restaurant_simulator.hpp"
#include <iostream>

uint16_t ask_for_number_of_clients()
{
    uint16_t num_of_clients;
    while (true)
    {
        std::cout << "Wprowadź liczbę gości których zamierzasz obsłużyć: (1-10) ";
        std::cin >> num_of_clients;
        if (num_of_clients <= 0 || num_of_clients > 10)
        {
            std::cout << "Wprowadź liczbę z przediału 1-10." << std::endl;
            continue;
        }
        break;
    }
    return num_of_clients;
}

int main()
{
    RestaurantSimulator simulator(Restaurant{"restaurant"});
    simulator.set_restaurant_attributes("menu.csv", "menu.csv");
    uint8_t num_of_clients = ask_for_number_of_clients();
    simulator.add_clients_to_queue(num_of_clients);
    // simulator.show_menu(std::cout);
    // simulator.show_tables_info(std::cout);
    // simulator.show_queue_info(std::cout);
};
