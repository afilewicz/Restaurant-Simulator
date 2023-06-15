#include "catch_amalgamated.hpp"
#include "../ready_order.hpp"

TEST_CASE("ReadyOrder - order")
{
    ReadyOrder ready_order(3);
    CHECK(ready_order.get_order_id() == 3);
    ready_order.add_dish(Dish(MenuItem("salad", 100, std::list<Ingredient>{})));
    ready_order.add_dish(Dish(MenuItem("pasta", 100, std::list<Ingredient>{})));
    CHECK(ready_order.get_dishes().size() == 2);
}