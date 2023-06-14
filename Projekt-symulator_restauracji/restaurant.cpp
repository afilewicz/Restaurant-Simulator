#include "restaurant.hpp"

Restaurant::Restaurant(std::string name) : name_(name) {}

std::string Restaurant::get_name() const
{
    return name_;
}

Waiter &Restaurant::get_waiter()
{
    return waiter.value();
}

Menu &Restaurant::get_menu()
{
    return menu.value();
}

std::map<uint, Table> &Restaurant::get_tables()
{
    return tables;
}

Kitchen &Restaurant::get_kitchen()
{
    return kitchen.value();
}

void Restaurant::add_table(const Table table)
{
    tables[table.get_id()] = table;
}

void Restaurant::remove_table(table_id table_id)
{
    tables.erase(table_id);
}

Table &Restaurant::get_table_by_id(table_id table_id)
{
    return tables.at(table_id);
}

void Restaurant::set_kitchen(Kitchen &new_kitchen)
{
    kitchen.emplace(new_kitchen);
}

void Restaurant::set_waiter(Waiter &new_waiter)
{
    waiter.emplace(new_waiter);
}

void Restaurant::set_menu(Menu &new_menu)
{
    menu.emplace(new_menu);
}

void Restaurant::set_tables(const std::map<table_id, Table> &new_tables)
{
    tables = new_tables;
}
