#include "catch_amalgamated.hpp"
#include "../waiter.hpp"
#include "../restaurant.hpp"

TEST_CASE("Waiter constructor")
{
    Restaurant restaurant("Restaurant");
    Waiter waiter(restaurant);
    std::map<uint32_t, Table> tables = {
        {0, Table{4}},
        {1, Table{3}},
        {2, Table{5}},
    };
    restaurant.set_tables(tables);
    std::optional<Table> table = waiter.get_free_table(3);
    CHECK(table.value().get_id() == 0);
}
