#include "restaurant.hpp"
#include "read_menu.hpp"
#include "read_tables.hpp"
#include <deque>

class RestaurantSimulator
{
public:
    RestaurantSimulator(Restaurant &&restaurant);
    void set_restaurant_attributes(std::string menu_path, std::string tables_path);
    void add_clients_to_queue(uint8_t number_of_clients);
    void let_in_one_group_and_place();              // exception if no groups in queue, do zrobienia
    void take_order_from_table(uint32_t table_id);  // do zrobienia
    void serve_ready_dish();                        // exception if no ready dishes, do zrobienia
    void bring_receipt_to_table(uint32_t table_id); // do zrobienia
    std::ostream &show_tables_info(std::ostream &os);
    std::ostream &show_queue_info(std::ostream &os);
    std::ostream &show_menu(std::ostream &os);

private:
    Menu load_menu(std::string path_to_file);
    void load_tables(std::string path_to_file); // do zrobienia

    Restaurant restaurant_;
    std::deque<ClientGroup> queue_;
};