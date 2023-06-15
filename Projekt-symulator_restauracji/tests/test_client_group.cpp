#include "catch_amalgamated.hpp"
#include "../client_group.hpp"

TEST_CASE()
{
    std::vector<Client> clients = std::vector<Client>{Client{}, Client{}};
    ClientGroup client_group(clients);
    CHECK(client_group.get_number_of_clients() == 2);
}