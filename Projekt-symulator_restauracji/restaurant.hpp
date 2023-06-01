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
        Kitchen kitchen;
        std::map<table_id, Table> tables;
    public:
        Restaurant(std::string, Waiter, Menu, Kitchen, std::map<uint, Table>);
        std::string get_name() const;
        Waiter& get_waiter();
        const Menu& get_menu() const;
        std::map<table_id, Table> get_tables();
        Kitchen& get_kitchen();
        void add_table(Table);
        void remove_table(table_id);
        Table& get_table_by_id(table_id);
};