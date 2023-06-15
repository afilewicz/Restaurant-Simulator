#include "catch_amalgamated.hpp"
#include "../kitchen.hpp"
#include "../restaurant.hpp"

TEST_CASE("Kitchen constructor")
{
    Restaurant restaurant("test_restaurant");
    Kitchen kitchen(restaurant);
    Order order = Order{1};
    Order &order_ref = order;
    kitchen.add_to_do_orders(order_ref);
    CHECK(kitchen.get_to_do_orders().size() == 1);
    CHECK(kitchen.get_ready_orders().size() == 0);
    kitchen.prepare_order(order_ref);
    CHECK(kitchen.get_to_do_orders().size() == 0);
    CHECK(kitchen.get_ready_orders().size() == 1);
}
TEST_CASE("kitchen - time to prepare")
{
    std::map<std::string, time_> new_time_to_prepare = {
        {"pizza", 3},
        {"pasta", 4},
        {"salad", 2},
    };
    Restaurant restaurant("test_restaurant");
    Kitchen kitchen(restaurant);
    kitchen.set_time_to_prepare(new_time_to_prepare);
}