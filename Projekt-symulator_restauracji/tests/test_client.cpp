#include "../client.hpp"
#include "catch_amalgamated.hpp"

TEST_CASE()
{
    Client client;
    REQUIRE(client.get_is_ready_to_order() == false);
    REQUIRE(client.get_is_ready_to_pay() == false);
    client.switch_flag(client.get_is_ready_to_order());
    client.switch_flag(client.get_is_ready_to_pay());
    REQUIRE(client.get_is_ready_to_order() == true);
    REQUIRE(client.get_is_ready_to_pay() == true);
}
