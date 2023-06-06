#include "catch_amalgamated.hpp"
#include "../waiter.hpp"
#include "../restaurant.hpp"

TEST_CASE("Waiter constructor")
{
    Restaurant restaurant("Restaurant");
    Waiter waiter(restaurant);
    CHECK(waiter.get_restaurant().get_name() == "Restaurant");
}