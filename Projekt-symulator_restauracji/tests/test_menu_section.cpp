#include "catch_amalgamated.hpp"
#include "../menu_section.hpp"

TEST_CASE("MenuSection constructor")
{
    MenuSection menu_section("Appetisers");
    CHECK(menu_section.get_name() == "Appetisers");

    SECTION("MenuSection constructor throws exception when name is empty")
    {
        CHECK_THROWS_AS(MenuSection(""), std::invalid_argument);
    }

    SECTION("set_name() changes name")
    {
        menu_section.set_name("Soups");
        CHECK(menu_section.get_name() == "Soups");
    }
    SECTION("set_name() throws exception when name is empty")
    {
        CHECK_THROWS_AS(menu_section.set_name(""), std::invalid_argument);
    }
    SECTION("add_menuitem() adds dish to list")
    {
        MenuItem dish("Soup", 10, {});
        menu_section.add_menuitem(dish);
        CHECK(menu_section.get_menuitems().size() == 1);
    }
    SECTION("remove_menuitem() removes dish from list")
    {
        MenuItem dish("Soup", 10, {});
        menu_section.add_menuitem(dish);
        CHECK(menu_section.get_menuitems().size() == 1);
        menu_section.remove_menuitem(dish);
        CHECK(menu_section.get_menuitems().size() == 0);
    }
}