#include "restaurant.hpp"

class RestaurantSimulator
{
public:
    RestaurantSimulator();
    Menu load_menu(std::string path_to_file);
    std::map<uint32_t, Table> load_tables(std::string path_to_file);

private:
}