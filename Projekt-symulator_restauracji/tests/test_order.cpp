#include "catch_amalgamated.hpp"
#include "../order.hpp"

TEST_CASE()
{
    Order order{1};
    CHECK(order.get_is_ready() == false);
    order.switch_is_ready();
    CHECK(order.get_is_ready() == true);
}