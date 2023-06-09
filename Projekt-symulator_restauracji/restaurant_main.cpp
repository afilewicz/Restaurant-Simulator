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
    std::ostream &os = std::cout;
    RestaurantSimulator simulator(Restaurant{"restaurant"});
    simulator.set_restaurant_attributes("menu.csv", "tables.csv");
    uint8_t num_of_clients = ask_for_number_of_clients();
    simulator.add_clients_to_queue(num_of_clients);
    // simulator.show_menu(std::cout);
    //  simulator.show_tables_info(std::cout);
    simulator.show_queue_info(os);
    simulator.let_in_one_group_and_place();
    simulator.let_in_one_group_and_place();
    simulator.let_in_one_group_and_place();
    simulator.let_in_one_group_and_place();
    simulator.show_tables_info(os);
    simulator.show_queue_info(os);

    Table& zero_table = simulator.get_restaurant().get_table_by_id(0);
    Client& first_client = zero_table.get_clients()[0];
    Client& second_client = zero_table.get_clients()[1];
    first_client.make_order(simulator.get_restaurant().get_menu());
    second_client.make_order(simulator.get_restaurant().get_menu());
    zero_table.switch_ready_to_order();

    simulator.take_order_from_table(0);
    simulator.preaparing_first_order();
};
