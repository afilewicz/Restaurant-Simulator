#include "catch_amalgamated.hpp"
#include "../receipt.hpp"
#include "../price_formatter.hpp"

TEST_CASE()
{
    SECTION("Receipt class test")
    {
        Order order(1);
        MenuItem menu_item("item1", 100, {});
        MenuItem menu_item2("item2", 200, {});
        order.add_dish(menu_item);
        order.add_dish(menu_item2);
        Receipt receipt(order);
        REQUIRE(receipt.get_order().get_table_id() == 1);
        REQUIRE(receipt.get_order().get_ordered_dishes().front().get_name() == "item1");
        REQUIRE(receipt.get_order().get_ordered_dishes().front().get_price() == 100);
        REQUIRE(receipt.get_order().get_ordered_dishes().back().get_name() == "item2");
        REQUIRE(receipt.get_order().get_ordered_dishes().back().get_price() == 200);
        REQUIRE(receipt.get_total_price() == 300);
    }
}