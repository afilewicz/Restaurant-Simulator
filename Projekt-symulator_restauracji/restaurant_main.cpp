#include "restaurant.hpp"
#include <iostream>

// Restaurant &init_restaurant()
// {
//     Menu menu{"menu1"};
//     Table table1{2};
//     Table table2{3};
//     Table table3{4};
//     std::map<uint32_t, Table> tables;
//     tables[table1.get_id()] = table1;
//     tables[table2.get_id()] = table2;
//     tables[table3.get_id()] = table3;
//     Restaurant restaurant{"siema", menu, tables};
//     Waiter waiter{restaurant};
//     Kitchen kitchen{restaurant};

//     Restaurant &restaurant_ref = restaurant;
//     return restaurant_ref;
// };

int main()
{
    Menu menu{"menu1"};
    Table table1{2};
    Table table2{3};
    Table table3{4};
    std::map<uint32_t, Table> tables;
    tables[table1.get_id()] = table1;
    tables[table2.get_id()] = table2;
    tables[table3.get_id()] = table3;
    Restaurant restaurant{"siema", menu, tables};
    Waiter waiter{restaurant};
    Kitchen kitchen{restaurant};
    restaurant.set_kitchen(kitchen);
    restaurant.set_waiter(waiter);

    uint32_t num_of_clients;
    std::cout << "Wprowadź liczbę osób, które przyjdą do restauracji: ";
    std::cin >> num_of_clients;

    while (true)
    {
        std::optional<Table> free_table = waiter.get_free_table(num_of_clients);
        if (free_table)
            std::cout << free_table.value().get_id();

        else
        {
            std::cout << "Niestety nie ma wolnego stolika" << std::endl;
            continue;
        }
    }
    return 0;
};
