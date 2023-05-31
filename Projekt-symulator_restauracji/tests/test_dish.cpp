#include "catch_amalgamated.hpp"
#include "../dish.hpp"

TEST_CASE("Dish constructor")
{
    Dish dish("Soup", 10, {});
    CHECK(dish.get_name() == "Soup");
    CHECK(dish.get_price() == 10);
    CHECK(dish.get_ingredients().size() == 0);

    SECTION("Dish constructor throws exception when name is empty")
    {
        CHECK_THROWS_AS(Dish("", 10, {}), std::invalid_argument);
    }

    SECTION("Dish constructor throws exception when price is negative")
    {
        CHECK_THROWS_AS(Dish("Soup", -10, {}), std::invalid_argument);
    }

    SECTION("set_name() changes name")
    {
        dish.set_name("Soup 2");
        CHECK(dish.get_name() == "Soup 2");
    }
    SECTION("set_name() throws exception when name is empty")
    {
        CHECK_THROWS_AS(dish.set_name(""), std::invalid_argument);
    }
    SECTION("set_price() changes price")
    {
        dish.set_price(15);
        CHECK(dish.get_price() == 15);
    }
    SECTION("set_price() throws exception when price is negative")
    {
        CHECK_THROWS_AS(dish.set_price(-10), std::invalid_argument);
    }
    SECTION("add_ingredient() adds ingredient to list")
    {
        Ingredient ingredient("pomidor", 30);
        dish.add_ingredient(ingredient);
        CHECK(dish.get_ingredients().size() == 1);
    }
    SECTION("remove_ingredient() removes ingredient from list")
    {
        Ingredient ingredient("pomidor", 30);
        dish.add_ingredient(ingredient);
        CHECK(dish.get_ingredients().size() == 1);
        dish.remove_ingredient(ingredient);
        CHECK(dish.get_ingredients().size() == 0);
    }
}