#include "catch_amalgamated.hpp"
#include "../dish.hpp"

TEST_CASE("Dish constructor")
{
    MenuItem menu_item("test", 100, std::list<Ingredient>{});
    Dish dish(menu_item);
    CHECK(dish.get_name() == "test");
}

TEST_CASE("Dish is_ready")
{
    MenuItem menu_item("test", 100, std::list<Ingredient>{});
    Dish dish(menu_item);
    CHECK(dish.get_is_ready() == false);
    dish.switch_is_ready();
    CHECK(dish.get_is_ready() == true);
}