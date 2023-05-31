#include "catch_amalgamated.hpp"
#include "../ingredient.hpp"

TEST_CASE("Ingredient constructor")
{
    Ingredient ingredient("pomidor", 30);
    CHECK(ingredient.get_name() == "pomidor");
    CHECK(ingredient.get_calories() == 30);

    SECTION("Ingredient constructor throws exception when name is empty")
    {
        CHECK_THROWS_AS(Ingredient("", 30), std::invalid_argument);
    }

    SECTION("Ingredient constructor throws exception when calories is negative")
    {
        CHECK_THROWS_AS(Ingredient("pomidor", -30), std::invalid_argument);
    }

    SECTION("set_name() changes name")
    {
        ingredient.set_name("pomidor 2");
        CHECK(ingredient.get_name() == "pomidor 2");
    }
    SECTION("set_name() throws exception when name is empty")
    {
        CHECK_THROWS_AS(ingredient.set_name(""), std::invalid_argument);
    }
    SECTION("set_calories() changes price")
    {
        ingredient.set_calories(40);
        CHECK(ingredient.get_calories() == 40);
    }
    SECTION("set_calories() throws exception when price is negative")
    {
        CHECK_THROWS_AS(ingredient.set_calories(-30), std::invalid_argument);
    }
}