#pragma once
#include "client.hpp"

class ClientGroup
{
public:
    ClientGroup(const std::vector<Client> clients);
    uint32_t get_number_of_clients() const;
    std::vector<Client> &get_clients();

private:
    std::vector<Client> clients_;
};