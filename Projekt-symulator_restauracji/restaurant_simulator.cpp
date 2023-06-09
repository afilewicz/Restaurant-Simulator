#include "restaurant_simulator.hpp"
#include "price_formatter.hpp"
#include <random>

RestaurantSimulator::RestaurantSimulator(Restaurant &&restaurant) : restaurant_(restaurant) {}

Restaurant& RestaurantSimulator::get_restaurant()
{
    return restaurant_;
}
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

void RestaurantSimulator::let_in_one_group_and_place()
{
    if (queue_.empty())
        {
            return;
        }
    ClientGroup first_group = queue_.front();
    std::optional<Table> table = restaurant_.get_waiter().get_free_table(first_group.get_number_of_clients());
    if (table)
    {
        restaurant_.get_waiter().place_at_table(*table, first_group);
        queue_.pop_front();
        restaurant_.remove_table(table.value().get_id());
        restaurant_.add_table(table.value());
    }
    else
        throw NoFreeTableError(first_group.get_clients().size());
}

// void RestaurantSimulator::let_in_one_group_and_place()
// {
//     if (queue_.empty())
//         throw EmptyQueueError();
//     ClientGroup first_group = queue_.front();
//     try
//     {
//         Table &table = restaurant_.get_waiter().get_free_table(first_group.get_number_of_clients());
//         restaurant_.get_waiter().place_at_table(table, first_group);
//         queue_.pop_front();
//     }
//     catch (NoFreeTableError &e)
//     {
//         throw NoFreeTableError(first_group.get_clients().size());
//     }
// }
void RestaurantSimulator::make_table_ready(table_id id)
{
    Table& table = restaurant_.get_table_by_id(id);
    for (auto& client: table.get_clients())
    {
        client.make_order(restaurant_.get_menu());
    }
    table.switch_ready_to_order();
}

void RestaurantSimulator::clean_table(table_id id)
{
    uint32_t seats = restaurant_.get_table_by_id(id).get_num_of_seats();
    restaurant_.remove_table(id);
    restaurant_.add_table(Table{id, seats});
}

void RestaurantSimulator::take_order_from_table(uint32_t table_id)
{
    if (restaurant_.get_table_by_id(table_id).get_ready_to_order() == true)
    {
        restaurant_.get_waiter().take_order(table_id);
        restaurant_.get_table_by_id(table_id).switch_ready_to_order();
    }
    else
        return;
}

table_id RestaurantSimulator::preaparing_first_order()
{
        Order &order = restaurant_.get_kitchen().get_to_do_orders().front();
        restaurant_.get_kitchen().prepairing_order(order);
        return order.get_table_id();
}

void RestaurantSimulator::serve_ready_dish(uint32_t table_id)
{
    for(auto dish : get_restaurant().get_kitchen().get_ready_dishes())
    {
        restaurant_.get_table_by_id(table_id).add_ready_dish(std::move(dish));
    }
}

void RestaurantSimulator::bring_receipt_to_table(uint32_t table_id)
{
    restaurant_.get_waiter().give_receipt(restaurant_.get_table_by_id(table_id));
    restaurant_.get_table_by_id(table_id).switch_ready_for_receipt();
}

std::ostream &RestaurantSimulator::show_tables_info(std::ostream &os)
{
    os << "Stoliki: " << std::endl;
    for (const auto &[id, table] : restaurant_.get_tables())
    {
        auto free_seats = table.get_free_seats();
        os << "\t"
           << "Stolik nr: " << id << ", wolnych miejsc: "
           << free_seats << "/" << table.get_num_of_seats()
           << ", gotowy do zamówienia: " << table.get_ready_to_order()
           << ", gotowy do rachunku: " << table.get_ready_for_receipt()
           << '\n';
    }
    os  << "\n";
    return os;
}

std::ostream &RestaurantSimulator::show_queue_info(std::ostream &os)
{
    if (queue_.empty())
    {
        os << "Kolejka jest pusta."  << "\n" << "\n";
        return os;
    }
    os << "Klienci w kolejce: " << std::endl;
    uint16_t counter = 1;
    for (const auto &group : queue_)
    {
        os << " " << counter << ". liczba osób: "
           << group.get_number_of_clients() << '\n';
        counter++;
    }
    os << "\n";
    return os;
}

std::ostream &RestaurantSimulator::show_menu(std::ostream &os)
{
    os << "Menu: " << std::endl;
    for (MenuSection menu_section : restaurant_.get_menu().get_menu_sections())
    {
        os << '\n';
        os << "  " << menu_section.get_name() << ":" << std::endl;
        for (const auto &[name, item] : menu_section.get_menu_items())
        {
            os << std::endl;
            os << "  - " << item.get_name() << "\t" << format_price(item.get_price())
               << " " << item.get_total_calories() << " kcal" << '\n';
            for (Ingredient ingredient : item.get_ingredients())
                os << "     * " << ingredient.get_name() << '\n';
        }
    }
    os << "\n";
    return os;
}