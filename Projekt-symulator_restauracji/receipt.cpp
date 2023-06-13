#include "receipt.hpp"
//#include "price_formatter.hpp"
#include <numeric>

Receipt::Receipt(Order order) : order_(order) {}

Order &Receipt::get_order()
{
    return order_;
}

int Receipt::get_total_price()
{
    return std::accumulate(order_.get_ordered_dishes().begin(), order_.get_ordered_dishes().end(), 0,
                           [](int sum, MenuItem item) { return sum + item.get_price(); });
}

std::ostream &Receipt::show_receipt(std::ostream &os)
{
    os << "Receipt nr " << order_.get_table_id() << std::endl;
    for (const auto &dish : order_.get_ordered_dishes())
        os << "\t" << dish.get_name() << " - " << dish.get_price() << std::endl;
    os << "Total: " << get_total_price() << std::endl;
    return os;
}