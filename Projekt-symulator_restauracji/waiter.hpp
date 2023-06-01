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
        std::list<std::shared_ptr<Order>> accepted_orders;
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
        std::list<std::shared_ptr<Order>> &get_accepted_orders();
        void add_accepted_order(std::shared_ptr<Order>);
        std::shared_ptr<Order> find_order_by_table_id(table_id);
        void remove_accepted_order(table_id);
        void take_order(table_id);
};

//problem był z tym że get_free_table musi coś zwracac