#include "restaurant.h"

Restaurant::Restaurant(std::string name, Waiter waiter, Menu menu, Kitchen kitchen):
    name(name), waiter(waiter), menu(menu), kitchen(kitchen)
    {};

std::string Restaurant::get_name() const
{
    return name;
};

Waiter& Restaurant::get_waiter()
{
    return waiter;
};

const Menu& Restaurant::get_menu() const
{
    return menu;
};

std::map<uint, Table>& Restaurant::get_tables()
{
    return tables;
};

Kitchen& Restaurant::get_kitchen()
{
    return kitchen;
};

void Restaurant::add_table(Table table)
{
    tables[table.get_id()] = table;
};
