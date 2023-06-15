#include "../table.hpp"
#include "catch_amalgamated.hpp"

TEST_CASE("Table constructor")
{
    Table table{1, 4};
    CHECK(table.get_id() == 1);
    CHECK(table.get_num_of_seats() == 4);
    SECTION("Table is occupied")
    {
        CHECK(table.get_is_occupied() == false);
        table.switch_is_occupied();
        CHECK(table.get_is_occupied() == true);
    }
    SECTION("Table is ready to order")
    {
        CHECK(table.get_ready_to_order() == false);
        table.switch_ready_to_order();
        CHECK(table.get_ready_to_order() == true);
    }
    SECTION("Table is ready for receipt")
    {
        CHECK(table.get_ready_for_receipt() == false);
        table.switch_ready_for_receipt();
        CHECK(table.get_ready_for_receipt() == true);
    }
    SECTION("Add client")
    {
        Client client1{};
        Client &client1_ref = client1;
        table.add_client(client1_ref);
        CHECK(table.get_clients().size() == 1);
        CHECK(table.get_free_seats() == 3);
    }
    SECTION("Switch ready to be cleaned")
    {
        CHECK(table.get_ready_to_be_cleaned() == false);
        table.switch_ready_to_be_cleaned();
        CHECK(table.get_ready_to_be_cleaned() == true);
    }
}