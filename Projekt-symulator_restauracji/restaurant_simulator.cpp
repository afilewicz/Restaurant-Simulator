#include "restaurant_simulator.hpp"
#include "price_formatter.hpp"
#include <random>

RestaurantSimulator::RestaurantSimulator(Restaurant &&restaurant) : restaurant_(restaurant) {}

void RestaurantSimulator::set_restaurant_attributes(std::string menu_path, std::string tables_path)
{
    Menu menu = load_menu(menu_path);
    load_tables(tables_path);
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

void RestaurantSimulator::load_tables(std::string path_to_file)
{
    read_tables_from_csv<Table>(path_to_file, restaurant_.get_tables());
}

void RestaurantSimulator::add_clients_to_queue(uint8_t num_of_clients)
{
    for (size_t i = 0; i < num_of_clients; i++)
    {
        std::vector<Client> clients = {};
        size_t n = rand() % 6 + 1;
        for (size_t j = 0; j < n; j++)
        {
            clients.emplace_back(Client{});
        }
        queue_.emplace_back(ClientGroup{clients});
    }
}

// void RestaurantSimulator::let_in_one_group_and_place()
// {
//     if (queue_.empty())
//         throw EmptyQueueError();
//     ClientGroup first_group = queue_.front();
//     std::optional<Table> table = restaurant_.get_waiter().get_free_table(first_group.get_number_of_clients());
//     if (table)
//     {
//         restaurant_.get_waiter().place_at_table(*table, first_group);
//         queue_.pop_front();
//     }
//     else
//         throw NoFreeTableError(first_group.get_clients().size());
// }

void RestaurantSimulator::let_in_one_group_and_place()
{
    if (queue_.empty())
        throw EmptyQueueError();
    ClientGroup first_group = queue_.front();
    try
    {
        Table &table = restaurant_.get_waiter().get_free_table(first_group.get_number_of_clients());
        restaurant_.get_waiter().place_at_table(table, first_group);
        queue_.pop_front();
    }
    catch (NoFreeTableError &e)
    {
        throw NoFreeTableError(first_group.get_clients().size());
    }
}

std::ostream &RestaurantSimulator::show_tables_info(std::ostream &os)
{
    os << "Stoliki: " << std::endl;
    for (const auto &[id, table] : restaurant_.get_tables())
    {
        auto free_seats = table.get_free_seats();
        os << "\t"
           << "Stolik nr: " << id << ", wolnych miejsc: "
           << free_seats << "/" << table.get_num_of_seats() << std::endl;
    }
    return os;
}

std::ostream &RestaurantSimulator::show_queue_info(std::ostream &os)
{
    os << "Klienci w kolejce: " << std::endl;
    uint16_t counter = 1;
    for (const auto &group : queue_)
    {
        os << " " << counter << ". liczba osób: "
           << group.get_number_of_clients() << std::endl;
        counter++;
    }
    return os;
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
            os << "  - " << item.get_name() << "\t" << format_price(item.get_price())
               << " " << item.get_total_calories() << " kcal" << std::endl;
            for (Ingredient ingredient : item.get_ingredients())
                os << "     * " << ingredient.get_name() << std::endl;
        }
    }
    return os;
}