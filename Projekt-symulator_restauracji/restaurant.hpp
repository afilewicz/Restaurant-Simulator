#pragma once
#include <string>
#include <map>
#include "waiter.hpp"
#include "menu.hpp"
#include "table.hpp"
#include "kitchen.hpp"
#include <optional>

class Restaurant
{

public:
    Restaurant(std::string name, Menu, std::map<uint32_t, Table>);
    std::string get_name() const;
    Waiter &get_waiter();
    const Menu &get_menu() const;
    std::map<table_id, Table> get_tables();
    Kitchen &get_kitchen();
    void add_table(Table);
    void remove_table(table_id);
    Table &get_table_by_id(table_id);
    void set_kitchen(Kitchen &kitchen);
    void set_waiter(Waiter &waiter);

private:
    std::string name;
    std::optional<Waiter> waiter;
    Menu menu;
    std::optional<Kitchen> kitchen;
    std::map<table_id, Table> tables;
};