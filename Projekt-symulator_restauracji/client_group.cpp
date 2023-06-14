#include "client_group.hpp"

ClientGroup::ClientGroup(const std::vector<Client> clients) : clients_(clients) {}

uint32_t ClientGroup::get_number_of_clients() const
{
    return clients_.size();
}

std::vector<Client> &ClientGroup::get_clients()
{
    return clients_;
}
