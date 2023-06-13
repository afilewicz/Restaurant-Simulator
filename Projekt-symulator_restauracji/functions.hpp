template <typename L, typename O>
void add_to(L list_of_orders, O order)
{
    list_of_orders.push_back(order);
}

template <typename L, typename O>
void remove_from(L list_of_orders, O order)
{
    list_of_orders.remove(order);
}