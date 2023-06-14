#pragma once
#include <set>
#include <optional>
#include "table.hpp"
#include "kitchen.hpp"
#include "client_group.hpp"
#include "exceptions.hpp"

class Waiter
{
private:
    std::set<table_id> serviced_tables;
    Restaurant &restaurant;
    bool is_busy = false;
    std::list<Order> accepted_orders;
    std::list<Receipt> receipts;

public:
    Waiter(Restaurant &);
    Restaurant &get_restaurant();
    // std::optional<Table> get_free_table(uint32_t number_of_seats);
    Table &get_free_table(uint32_t number_of_seats);
    std::set<table_id> get_serviced_tables() const;
    bool get_is_busy() const;
    void switch_busy();
    void place_at_table(Table &, ClientGroup);
    void give_receipt(Table &);
    std::list<Order> &get_accepted_orders();
    void add_accepted_order(const std::optional<Order>);
    std::optional<Order> find_order_by_table_id(table_id);
    void remove_accepted_order(table_id);
    void take_order(table_id);
    void add_receipt(const Receipt Receipt);
    std::optional<Receipt> take_proper_receipt(const Table table);
};

// problem był z tym że get_free_table musi coś zwracac