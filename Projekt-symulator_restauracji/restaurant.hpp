#pragma once
#include <string>
#include <map>
#include <optional>
#include "waiter.hpp"


class Kitchen;

class Menu;

class Table;

class Restaurant
{

public:
    Restaurant(std::string name);
    std::string get_name() const;
    Waiter &get_waiter();
    Menu &get_menu();
    std::map<table_id, Table> &get_tables();
    Kitchen &get_kitchen();
    void add_table(const Table table);
    void remove_table(table_id);
    Table &get_table_by_id(table_id);
    void set_kitchen(Kitchen &kitchen);
    void set_waiter(Waiter &waiter);
    void set_menu(Menu &menu);
    void set_tables(const std::map<table_id, Table> &tables);

private:
    std::string name_;
    std::optional<Waiter> waiter;
    std::optional<Menu> menu;
    std::optional<Kitchen> kitchen;
    std::map<table_id, Table> tables = {};
};