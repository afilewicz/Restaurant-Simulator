#include "restaurant.hpp"

Restaurant::Restaurant(std::string name, Menu menu, std::map<uint32_t, Table> tables) : name(name), menu(menu), tables(tables) {}

std::string Restaurant::get_name() const
{
    return name;
}

Waiter &Restaurant::get_waiter()
{
    return waiter.value();
}

const Menu &Restaurant::get_menu() const
{
    return menu;
}

std::map<uint, Table> Restaurant::get_tables()
{
    return tables;
}

Kitchen &Restaurant::get_kitchen()
{
    return kitchen.value();
}

void Restaurant::add_table(Table table)
{
    tables[table.get_id()] = table;
}

void Restaurant::remove_table(table_id table_id)
{
    tables.erase(table_id);
}

Table &Restaurant::get_table_by_id(table_id table_id)
{
    return tables[table_id];
}

void Restaurant::set_kitchen(Kitchen &new_kitchen)
{
    kitchen.emplace(new_kitchen);
}

void Restaurant::set_waiter(Waiter &new_waiter)
{
    waiter.emplace(new_waiter);
}
