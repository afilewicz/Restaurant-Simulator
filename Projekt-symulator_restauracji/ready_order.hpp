#include "dish.hpp"

class ReadyOrder
{
public:
    ReadyOrder(table_id table_id);
    void add_dish(Dish &&new_dish);
    table_id get_order_id();
    std::list<Dish> &get_dishes();

private:
    table_id table_id_;
    std::list<Dish> dishes_;
};