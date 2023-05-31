#pragma once
#include <set>
#include "table.hpp"
#include "client.hpp"
#include "receipt.hpp"

class Restaurant;

class Waiter
{
    private:
        std::set<table_id> serviced_tables;
        Restaurant& restaurant;
        bool is_busy = false;
    public:
        Waiter(Restaurant&);
        Restaurant& get_restaurant();
        bool is_free_table();
        Table get_free_table();
        std::set<table_id> get_serviced_tables();
        bool get_is_busy();
        void switch_busy();
        void place_at_table(Table, Client);
        void look_for_action();
        void give_receipt(Table, Receipt);
        void search_ready_order();
};

//problem był z tym że get_free_table musi coś zwracac