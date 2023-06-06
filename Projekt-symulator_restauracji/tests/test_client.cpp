#include "../client.hpp"
#include "catch_amalgamated.hpp"

TEST_CASE()
{
    Client client;
    client.switch_flag(client.get_is_ready_to_order());
    client.switch_flag(client.get_is_ready_to_pay());
    REQUIRE(client.get_is_ready_to_order() == true);
    REQUIRE(client.get_is_ready_to_pay() == true);
}
