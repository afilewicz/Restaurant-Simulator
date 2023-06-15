#include "restaurant_simulator.hpp"
#include "price_formatter.hpp"
#include <iostream>
#include <random>

uint16_t ask_for_number_of_group_of_clients()
{
    uint16_t num_of_clients;
    while (true)
    {
        std::cout << "\nWprowadź liczbę grup gości których zamierzasz obsłużyć: (1-10) ";
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

void print_instruction()
{
    std::cout << "\nLista poleceń: \n";
    std::cout << "t - wyświetl informacje o stolikach\n";
    std::cout << "q - wyświetl informacje o kolejce\n";
    std::cout << "m - wyświetl menu\n";
    std::cout << "k - wyświetl informacje o kuchni\n";
    std::cout << "e - zaproś jedną grupę klientów do restauracji\n";
    std::cout << "o - przyjmij zamówienie od stolika\n";
    std::cout << "p - przygotuj pierwsze z listy zamówienie\n";
    std::cout << "s - zaserwuj gotowe zamówienie do stolika\n";
    std::cout << "r - przynieś rachunek do stolika\n";
    std::cout << "c - posprzątaj stolik\n";
    std::cout << "i - wyświetl listę poleceń\n";
}

void print_intro()
{
    std::cout << "Witaj w symulatorze restauracji! \n";
}

int main()
{
    print_intro();
    std::ostream &os = std::cout;
    RestaurantSimulator simulator(Restaurant{"restaurant"});
    simulator.set_restaurant_attributes("menu.csv", "tables.csv");
    uint8_t num_of_clients = ask_for_number_of_group_of_clients();
    simulator.add_clients_to_queue(num_of_clients);
    print_instruction();
    while (true)
    {
        char instr;
        std::cout << "\nWprowadź polecenie: ";
        std::cin >> instr;
        if (instr == 't')
            simulator.show_tables_info(os);
        else if (instr == 'q')
            simulator.show_queue_info(os);
        else if (instr == 'm')
            simulator.show_menu(os);
        else if (instr == 'k')
            simulator.show_kitchen_info(os);
        else if (instr == 'e')
        {
            try
            {
                simulator.let_in_one_group_and_place();
                std::cout << "\nGrupa klientów została wpuszczona do restauracji. \n";
            }
            catch (const NoClientsInQueueError &e)
            {
                std::cout << "Brak klientów w kolejce. \n";
                continue;
            }
            catch (const NoFreeTableError &e)
            {
                std::cout << "Aktualnie nie ma wolnych stolików. \n";
                continue;
            }
        }
        else if (instr == 'p')
        {
            try
            {
                simulator.prepare_first_order();
                std::cout << "Zamówienie zostało przygotowane. \n";
            }
            catch (const NoOrdersToPrepareError &e)
            {
                std::cout << "Brak zamówień do realizacji. \n";
                continue;
            }
        }
        else if (instr == 'o')
        {
            std::string id;
            while (true)
            {
                std::cout << "Podaj id stolika: ";
                std::cin >> id;
                if (id == "q")
                    break;
                try
                {
                    simulator.take_order_from_table(std::stoi(id));
                    std::cout << "Zebrano zamówienie. \n";
                    break;
                }
                catch (const TableNotReadyToOrderError &e)
                {
                    std::cout << "Stolik o danym numerze nie jest gotowy do przyjmowania zamówień. \nWprowadź inną liczbę lub 'q' aby wyjść.\n";
                    continue;
                }
            }
        }
        else if (instr == 's')
        {
            std::string id;
            while (true)
            {
                std::cout << "Podaj id stolika: ";
                std::cin >> id;
                if (id == "q")
                    break;
                try
                {
                    simulator.serve_ready_order(std::stoi(id));
                    break;
                }
                catch (const OrderNotFoundError &e)
                {
                    std::cout << "Nie odnaleziono zamówienia dla podanego stolika. \nWprowadź inną liczbę lub 'q' aby wyjść.\n";
                    continue;
                }
            }
        }
        else if (instr == 'r')
        {
            std::string id;
            while (true)
            {
                std::cout << "Podaj id stolika: ";
                std::cin >> id;
                if (id == "q")
                    break;
                try
                {
                    simulator.bring_receipt_to_table(std::stoi(id));
                    break;
                }
                catch (const TableNotReadyToPayError &e)
                {
                    std::cout << "Stolik o danym numerze nie jest gotowy do zapłaty. \nWprowadź inną liczbę lub 'q' aby wyjść.\n";
                    continue;
                }
            }
        }
        else if (instr == 'c')
        {
            std::string id;
            while (true)
            {
                std::cout << "Podaj id stolika: ";
                std::cin >> id;
                if (id == "q")
                    break;
                try
                {
                    simulator.clean_table(std::stoi(id));
                    break;
                }
                catch (const TableNotReadyToBeCleanedError &e)
                {
                    std::cout << "Stolik o danym numerze nie jest gotowy do sprzątania. \nWprowadź inną liczbę lub 'q' aby wyjść.\n";
                    continue;
                }
            }
        }
        else if (instr == 'x')
            break;
        else if (instr == 'i')
            print_instruction();
        else
            std::cout << "Nieznane polecenie. Spróbuj ponownie.\n";
    }
    return 0;
};
