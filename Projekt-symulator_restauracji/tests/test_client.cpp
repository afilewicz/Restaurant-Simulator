#include "../client.hpp"
#include "catch_amalgamated.hpp"

TEST_CASE("Client constructor", "[client]")
{
    Client client;
    REQUIRE(client.get_is_ready_to_order() == false);
    REQUIRE(client.get_is_ready_to_pay() == false);

    SECTION("Client::switch_flag")
    {
        bool flag = client.get_is_ready_to_order();
        client.switch_flag(flag);
        REQUIRE(client.get_is_ready_to_order() == true);
        client.switch_flag(flag);
        REQUIRE(client.get_is_ready_to_order() == false);
    }

    SECTION("Client::get_chosen_dishes")
    {
        REQUIRE(client.get_chosen_dishes().size() == 0);
    }
}
