#include "restaurant_simulator.hpp"
#include "price_formatter.hpp"
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

    //bedziemy losować table_id
    simulator.make_table_ready(0);
    simulator.show_tables_info(os);

    //uzytkownik poda id z którego bedzie losować
    simulator.take_order_from_table(0);
    if (!simulator.get_restaurant().get_kitchen().get_to_do_orders().empty())
    {
        table_id id = simulator.preaparing_first_order();
        simulator.serve_ready_dish(id);
    }

    //do zmiany musi to byc jakis czas po jedzeniu klienta
    simulator.get_restaurant().get_table_by_id(0).switch_ready_for_receipt();

    simulator.show_tables_info(os);

    if (simulator.get_restaurant().get_table_by_id(0).get_ready_for_receipt())
    {
        //ogarnać receipt
        simulator.bring_receipt_to_table(0);
        simulator.get_restaurant().get_table_by_id(0).get_receipt().show_receipt(os);
        simulator.clean_table(0);
    }
    simulator.show_tables_info(os);
};
