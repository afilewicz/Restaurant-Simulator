#pragma once
#include <set>
#include "restaurant.h"
#include "table.h"
#include "client.h"
#include "receipt.h"


class Waiter
{
    private:
        std::set<table_id> serviced_tables;
        Restaurant restaurant;
        bool is_busy;
    public:
        Table get_free_table();
        std::set<table_id> get_serviced_tables();
        bool get_is_busy();
        void switch_busy(bool is_busy);
        void place_at_table(Table table, Client client);
        void look_for_action();
        void give_receipt(Table table, Receipt receipt);
        void search_ready_order();
};