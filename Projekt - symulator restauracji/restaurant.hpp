#pragma once
#include <string>
#include <map>
#include "waiter.hpp"
#include "menu.hpp"
#include "table.hpp"
#include "kitchen.hpp"

class Restaurant
{
    private:
        std::string name;
        Waiter waiter;
        Menu menu;
        std::map<uint, Table> tables;
        Kitchen kitchen;
    public:
        Restaurant(std::string name, Waiter waiter, Menu menu, Kitchen kitchen);
        std::string get_name() const;
        Waiter& get_waiter();
        const Menu& get_menu() const;
        std::map<uint, Table>& get_tables();
        Kitchen& get_kitchen();
        void add_table(const Table table);
        void remove_table(uint table_id);
        Table get_table_by_id(uint table_id);
};