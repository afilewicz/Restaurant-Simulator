#include "catch_amalgamated.hpp"
#include "../kitchen.hpp"
#include "../restaurant.hpp"

TEST_CASE("Kitchen constructor")
{
    Restaurant restaurant("test_restaurant");
    Kitchen kitchen(restaurant);
}