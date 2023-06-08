#include "catch_amalgamated.hpp"
#include "../menu.hpp"

TEST_CASE("Menu constructor")
{
    Menu menu;
    CHECK(menu.get_menu_sections().size() == 0);

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