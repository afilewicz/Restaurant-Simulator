#include "catch_amalgamated.hpp"
#include "../order.hpp"

TEST_CASE()
{
    Order order{1};
    CHECK(order.get_is_ready() == false);
    order.switch_is_ready();
    CHECK(order.get_is_ready() == true);
    order.add_dish(MenuItem{"salad", 100, std::list<Ingredient>{}});
    order.add_dish(MenuItem("pasta", 100, std::list<Ingredient>{}));
    CHECK(order.get_ordered_dishes().size() == 2);
}

TEST_CASE("Order - table id")
{
    Order order{1};
    CHECK(order.get_table_id() == 1);
}

TEST_CASE("order = order_1")
{
    Order order{1};
    Order order1{1};
    CHECK(order == order1);
}