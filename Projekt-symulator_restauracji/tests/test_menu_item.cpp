#include "catch_amalgamated.hpp"
#include "../menuitem.hpp"

TEST_CASE("MenuItem constructor")
{
    MenuItem menuitem("Soup", 10, {});
    CHECK(menuitem.get_name() == "Soup");
    CHECK(menuitem.get_price() == 10);
    CHECK(menuitem.get_ingredients().size() == 0);

    SECTION("MenuItem constructor throws exception when name is empty")
    {
        CHECK_THROWS_AS(MenuItem("", 10, {}), std::invalid_argument);
    }

    SECTION("MenuItem constructor throws exception when price is negative")
    {
        CHECK_THROWS_AS(MenuItem("Soup", -10, {}), std::invalid_argument);
    }

    SECTION("set_name() changes name")
    {
        menuitem.set_name("Soup 2");
        CHECK(menuitem.get_name() == "Soup 2");
    }
    SECTION("set_name() throws exception when name is empty")
    {
        CHECK_THROWS_AS(menuitem.set_name(""), std::invalid_argument);
    }
    SECTION("set_price() changes price")
    {
        menuitem.set_price(15);
        CHECK(menuitem.get_price() == 15);
    }
    SECTION("set_price() throws exception when price is negative")
    {
        CHECK_THROWS_AS(menuitem.set_price(-10), std::invalid_argument);
    }
    SECTION("add_ingredient() adds ingredient to list")
    {
        Ingredient ingredient("pomidor", 30);
        menuitem.add_ingredient(ingredient);
        CHECK(menuitem.get_ingredients().size() == 1);
    }
    SECTION("remove_ingredient() removes ingredient from list")
    {
        Ingredient ingredient("pomidor", 30);
        menuitem.add_ingredient(ingredient);
        CHECK(menuitem.get_ingredients().size() == 1);
        menuitem.remove_ingredient(ingredient);
        CHECK(menuitem.get_ingredients().size() == 0);
    }
}