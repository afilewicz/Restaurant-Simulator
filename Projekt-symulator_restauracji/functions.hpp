template <typename List, typename Order>
void add_to(List list_of_orders, Order order)
{
    list_of_orders.push_back(order);
}

template <typename List, typename Order>
void remove_from(List list_of_orders, Order order)
{
    list_of_orders.remove(order);
}
