#include "catch_amalgamated.hpp"
#include "../waiter.hpp"
#include "../restaurant.hpp"
#include "../client_group.hpp"

TEST_CASE("Waiter constructor")
{
    Restaurant restaurant("test_restaurant");
    Menu menu = {};
    std::map<uint32_t, Table> tables = std::map<uint32_t, Table>{
        {0, Table{4}},
        {1, Table{3}},
        {2, Table{2}},
        {3, Table{6}},
    };
    Waiter waiter{restaurant};
    Kitchen kitchen{restaurant};
    restaurant.set_waiter(waiter);
    restaurant.set_kitchen(kitchen);
    restaurant.set_menu(menu);
    restaurant.set_tables(tables);

    SECTION("get_free_table")
    {
        Table table = restaurant.get_table_by_id(2);
        //CHECK(waiter.get_free_table(4) == std::optional<Table>(table));
        /*CHECK(waiter.get_free_table(4) != std::nullopt);
        CHECK(waiter.get_free_table(5) != std::nullopt);
        CHECK(waiter.get_free_table(10) == std::nullopt);*/
    };

    SECTION("get_serviced_tables")
    {
        CHECK(waiter.get_serviced_tables() == std::set<table_id>{});
    };

    SECTION("get_serviced_tables_2")
    {
        Client client;
        ClientGroup client_group{std::vector<Client>{client}};
        waiter.place_at_table(restaurant.get_table_by_id(2), client_group);
        CHECK(waiter.get_serviced_tables() == std::set<table_id>{2});
    };

    SECTION("is_busy")
    {
        CHECK(waiter.get_is_busy() == false);
        waiter.switch_busy();
        CHECK(waiter.get_is_busy() == true);
    };
}
