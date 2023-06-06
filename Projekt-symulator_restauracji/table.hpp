#pragma once
#include <vector>
#include <list>
#include <memory>
#include <optional>
#include "client.hpp"
#include "order.hpp"
#include "receipt.hpp"

using table_id = unsigned int;

class Order;

class Table
{
public:
    Table();
    table_id get_id() const;
    bool get_is_occupied() const;
    void switch_flag(bool &flag);
    void switch_is_occupied();
    bool get_ready_to_order() const;
    void switch_ready_to_order();
    std::vector<Client> &get_clients();
    bool get_ready_for_receipt() const;
    void get_ready_dishes() const;
    void place_order_on_table(Order &);
    void switch_ready_for_receipt();

private:
    table_id id;
    bool is_occupied = false;
    bool ready_to_order = false;
    std::vector<Client> clients;
    bool ready_for_receipt = false;
    std::list<Order> ready_orders;
    // std::optional<Receipt> receipt = std::nullopt;
    // stawianie na stół dań i rachunku
};
