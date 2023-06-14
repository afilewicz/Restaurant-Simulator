#include "order.hpp"

class ReadyOrder
{
public:
    ReadyOrder(table_id table_id);
    void add_dish(Dish &&new_dish);

private:
    table_id table_id_;
    std::list<Dish> dishes_;
};