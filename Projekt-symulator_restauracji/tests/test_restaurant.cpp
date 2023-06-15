#include "catch_amalgamated.hpp"
#include "../restaurant.hpp"

TEST_CASE("Restaurant constructor")
{
    Restaurant restaurant("test_restaurant");
    Menu menu = {};
    std::map<uint32_t, Table> tables = std::map<uint32_t, Table>{
        {0, Table{0, 4}},
        {1, Table{1, 3}},
        {2, Table{2, 2}},
        {3, Table{3, 6}},
    };
    Waiter waiter{restaurant};
    Kitchen kitchen{restaurant};
    restaurant.set_waiter(waiter);
    restaurant.set_kitchen(kitchen);
    restaurant.set_menu(menu);
    restaurant.set_tables(tables);

    SECTION("get_name")
    {
        CHECK(restaurant.get_name() == "test_restaurant");
    };

    SECTION("add_table")
    {
        CHECK(restaurant.get_tables().size() == 4);
        restaurant.add_table(Table{4, 5});
        CHECK(restaurant.get_tables().size() == 5);
    };

    SECTION("get_table_by_id")
    {
        CHECK(restaurant.get_table_by_id(2).get_id() == 2);
        CHECK(restaurant.get_table_by_id(2).get_num_of_seats() == 2);
    };

    SECTION("remove_table")
    {
        CHECK(restaurant.get_tables().size() == 4);
        restaurant.remove_table(2);
        CHECK(restaurant.get_tables().size() == 3);
    };
}