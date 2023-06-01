#include "client.hpp"

Client::Client()
{
}

bool Client::get_is_ready_to_order() const
{
    return is_ready_to_order;
}

bool Client::get_is_ready_to_pay() const
{
    return is_ready_to_pay;
}

void Client::switch_flag(bool &&flag)
{
    flag = !flag;
}

std::vector<MenuItem> Client::get_chosen_dishes() const
{
    return chosen_dishes;
}
