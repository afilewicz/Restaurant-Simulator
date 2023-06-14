#include "restaurant_simulator.hpp"
#include "price_formatter.hpp"
#include <iostream>
#include <random>

uint16_t ask_for_number_of_group_of_clients()
{
    uint16_t num_of_clients;
    while (true)
    {
        std::cout << "Wprowadź liczbę grup gości których zamierzasz obsłużyć: (1-10) ";
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
    uint8_t num_of_clients = ask_for_number_of_group_of_clients();
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

    // losowanie do momentu wylosowania zajetego stolika
    table_id id;
    do
    {
        id = simulator.drawn_id();
    } while (simulator.get_restaurant().get_table_by_id(id).get_is_occupied() != true);

    simulator.make_table_ready(id);
    simulator.show_tables_info(os);

    // uzytkownik poda id z którego bedzie chcial cos robic
    table_id user_id = id;

    simulator.take_order_from_table(user_id);
    if (simulator.get_restaurant().get_table_by_id(user_id).get_is_occupied())
    {
        os << "The dishes are being prepaired ..." << std::endl;
        table_id id = simulator.preaparing_first_order();
        simulator.serve_ready_order(id);
    }
    else
    {
        os << "This table isn't occupied, choose another table." << std::endl;
    }

    // do zmiany musi to byc jakis czas po jedzeniu klienta
    if (simulator.get_restaurant().get_table_by_id(user_id).get_is_occupied())
    {
        simulator.get_restaurant().get_table_by_id(user_id).switch_ready_for_receipt();
    }

    simulator.show_tables_info(os);

    if (simulator.get_restaurant().get_table_by_id(user_id).get_ready_for_receipt())
    {
        // ogarnać receipt
        simulator.bring_receipt_to_table(user_id);
        simulator.get_restaurant().get_table_by_id(user_id).get_receipt().show_receipt(os);
        simulator.clean_table(user_id);
    }
    simulator.show_tables_info(os);
};
