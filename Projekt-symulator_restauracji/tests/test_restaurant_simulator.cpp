#include "../restaurant_simulator.hpp"
#include "catch_amalgamated.hpp"

TEST_CASE("Test set_restaurant_attributes")
{
    RestaurantSimulator restaurant_simulator{Restaurant("test_restaurant")};
    std::map<std::string, time_> new_time_to_prepare = {
        {"pizza", 3},
        {"pasta", 4},
        {"salad", 2},
    };
    std::vector<std::string> new_menu = {"pizza", "pasta", "salad"};
    restaurant_simulator.set_restaurant_attributes("../menu.csv", "../tables.csv");
    CHECK(restaurant_simulator.get_restaurant().get_menu().get_menu_sections().front().get_name() == "Przystawki");
    CHECK(restaurant_simulator.get_restaurant().get_name() == "test_restaurant");

    SECTION("add client_group to queue")
    {
        restaurant_simulator.add_clients_to_queue(1);
        restaurant_simulator.let_in_one_group_and_place();
    };
}
