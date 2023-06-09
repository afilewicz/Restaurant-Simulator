#include "restaurant.hpp"
#include "read_menu.hpp"
#include "read_tables.hpp"
#include <deque>

class RestaurantSimulator
{
public:
    RestaurantSimulator(Restaurant &&restaurant);
    Restaurant& get_restaurant();
    void set_restaurant_attributes(std::string menu_path, std::string tables_path);
    void add_clients_to_queue(uint8_t number_of_clients);
    void let_in_one_group_and_place();
    void make_table_ready(table_id id);
    void clean_table(table_id id);
    void take_order_from_table(uint32_t table_id);
    table_id preaparing_first_order();
    void serve_ready_dish(uint32_t table_id);
    void bring_receipt_to_table(uint32_t table_id);
    std::ostream &show_tables_info(std::ostream &os);
    std::ostream &show_queue_info(std::ostream &os);
    std::ostream &show_menu(std::ostream &os);

private:
    Menu load_menu(std::string path_to_file);
    void load_tables(std::string path_to_file);

    Restaurant restaurant_;
    std::deque<ClientGroup> queue_;
};