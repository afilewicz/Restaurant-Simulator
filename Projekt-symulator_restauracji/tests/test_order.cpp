#include "catch_amalgamated.hpp"
#include "../order.hpp"

TEST_CASE("Test order class", "[order]")
{
    SECTION("Create order")
    {
        Order order(1);
        REQUIRE(order.get_table_id() == 1);
        REQUIRE(order.get_ordered_dishes().empty() == true);
        REQUIRE(order.get_is_ready() == false);
    }
    SECTION("Add dish to order")
    {
        Order order(1);
        MenuItem dish("dish", 10, {});
        order.add_dish(dish);
        REQUIRE(order.get_ordered_dishes().size() == 1);
        REQUIRE(order.get_ordered_dishes().front().get_name() == "dish");
        REQUIRE(order.get_ordered_dishes().front().get_price() == 10);
    }
    SECTION("Switch is ready")
    {
        Order order(1);
        REQUIRE(order.get_is_ready() == false);
        order.switch_is_ready();
        REQUIRE(order.get_is_ready() == true);
        order.switch_is_ready();
        REQUIRE(order.get_is_ready() == false);
    }
}