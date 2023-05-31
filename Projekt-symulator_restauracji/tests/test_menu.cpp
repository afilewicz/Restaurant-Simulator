#include "catch_amalgamated.hpp"
#include "../menu.hpp"

TEST_CASE("Menu constructor")
{
    Menu menu("Menu");
    CHECK(menu.get_name() == "Menu");

    SECTION("Menu constructor throws exception when name is empty")
    {
        CHECK_THROWS_AS(Menu(""), std::invalid_argument);
    }

    SECTION("set_name() changes name")
    {
        menu.set_name("Menu 2");
        CHECK(menu.get_name() == "Menu 2");
    }
    SECTION("set_name() throws exception when name is empty")
    {
        CHECK_THROWS_AS(menu.set_name(""), std::invalid_argument);
    }
    SECTION("add_menu_section() adds menu section to list")
    {
        MenuSection menu_section("Appetisers");
        menu.add_menu_section(menu_section);
        CHECK(menu.get_menu_sections().size() == 1);
    }
    SECTION("remove_menu_section() removes menu section from list")
    {
        MenuSection menu_section("Appetisers");
        menu.add_menu_section(menu_section);
        CHECK(menu.get_menu_sections().size() == 1);
        menu.remove_menu_section(menu_section);
        CHECK(menu.get_menu_sections().size() == 0);
    }
}