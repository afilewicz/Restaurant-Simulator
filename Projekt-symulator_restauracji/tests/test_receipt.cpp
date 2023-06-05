#include "catch_amalgamated.hpp"
#include "../receipt.hpp"

TEST_CASE()
{
    SECTION("Receipt class test")
    {
        Order order(1);
        MenuItem menu_item("test dish", 100, {});
        order.add_dish(menu_item);
        Receipt receipt(order);
        REQUIRE(receipt.get_order().get_table_id() == 1);
        REQUIRE(receipt.get_order().get_ordered_dishes().front().get_name() == "test dish");
        REQUIRE(receipt.get_order().get_ordered_dishes().front().get_price() == 100);
        REQUIRE(receipt.get_total_price() == 100);
    }
}