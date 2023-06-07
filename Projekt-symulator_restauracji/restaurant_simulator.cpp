#include "restaurant_simulator.hpp"
#include "price_formatter.hpp"

RestaurantSimulator::RestaurantSimulator(Restaurant &&restaurant) : restaurant_(restaurant) {}

void RestaurantSimulator::set_restaurant_attributes(std::string menu_path, std::string tables_path)
{
    Menu menu = load_menu(menu_path);
    // std::map<uint32_t, Table> tables = load_tables(tables_path);
    Waiter waiter{restaurant_};
    Kitchen kitchen{restaurant_};
    restaurant_.set_waiter(waiter);
    restaurant_.set_kitchen(kitchen);
    restaurant_.set_menu(menu);
}

Menu RestaurantSimulator::load_menu(std::string path_to_file)
{
    Menu menu{};
    read_from_csv<MenuItem, Menu, Ingredient>(path_to_file, menu);
    return menu;
}

std::ostream &RestaurantSimulator::show_menu(std::ostream &os)
{
    os << "Menu: " << std::endl;
    for (MenuSection menu_section : restaurant_.get_menu().get_menu_sections())
    {
        os << std::endl;
        os << "  " << menu_section.get_name() << ":" << std::endl;
        for (const auto &[name, item] : menu_section.get_menu_items())
        {
            os << std::endl;
            os << "  - " << item.get_name() << "\t" << format_price(item.get_price()) << " PLN, " << item.get_total_calories() << " kcal" << std::endl;
            for (Ingredient ingredient : item.get_ingredients())
                os << "     * " << ingredient.get_name() << std::endl;
        }
    }
    return os;
}
