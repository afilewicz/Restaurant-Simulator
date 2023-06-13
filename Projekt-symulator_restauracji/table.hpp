#pragma once
#include <vector>
#include <list>
#include <memory>
#include <optional>
#include "client.hpp"
#include "order.hpp"
#include "receipt.hpp"

using table_id = uint32_t;

class Table
{
public:
    Table(table_id id, uint32_t num_of_seats);
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
    uint32_t get_num_of_seats() const;
    uint32_t get_free_seats() const;
    void add_client(Client &client);
    std::list<Dish>& get_ready_dishes();
    void add_ready_dish(Dish dish);
    void place_receipt(Receipt new_receipt);
    Receipt get_receipt();

private:
    table_id id;
    bool is_occupied = false;
    bool ready_to_order = false;
    std::vector<Client> clients = {};
    bool ready_for_receipt = false;
    std::list<Order> ready_orders;
    uint32_t number_of_seats_ = 0;
    std::list<Dish> ready_dishes;
    std::optional<Receipt> receipt = std::nullopt;
    // stawianie na stół dań i rachunku
};
