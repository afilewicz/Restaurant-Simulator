#include "client.hpp"

class ClientGroup
{
public:
    ClientGroup(std::vector<Client> clients);
    uint32_t get_number_of_clients() const;

private:
    std::vector<Client> clients_;
};