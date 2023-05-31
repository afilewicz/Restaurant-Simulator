#pragma once
#include <vector>
#include <list>
#include <memory>
#include "client.hpp"

using table_id = unsigned int;

class Order;

class Table
{
    private:
        table_id id;
        bool is_occupied = false;
        bool ready_to_order = false;
        std::vector<Client> clients;
        bool ready_for_receipt = false;
        std::list<std::unique_ptr<Order>> ready_orders;
    public:
        Table();
        table_id get_id() const;
        bool get_is_occupied() const;
        void switch_is_occupied();
        bool get_ready_to_order() const;
        void switch_ready_to_order();
        std::vector<Client> get_clients();
        bool get_ready_for_receipt();
        void get_ready_dishes();
        void add_ready_order(std::unique_ptr<Order> order_ptr);
};
