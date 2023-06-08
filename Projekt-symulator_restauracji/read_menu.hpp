#pragma once
#include <string>
#include <list>
#include "rapidcsv.h"

template <typename I>
std::list<I> parse_ingredient_list(std::string ingredient_string)
{
    std::list<I> result;
    std::stringstream ss{ingredient_string};
    std::string item;
    char delim = ';';

    Ingredient current_ingredient;
    for (int i = 0; getline(ss, item, delim); ++i)
    {
        if (i % 2 == 0)
        {
            current_ingredient.set_name(item);
        }
        else
        {
            current_ingredient.set_calories(std::stoi(item));
            result.push_back(current_ingredient);
        }
    }
    return result;
}

template <typename I, typename M, typename In>
void read_from_csv(std::string file_path, M &menu)
{
    rapidcsv::Document doc(file_path, rapidcsv::LabelParams(0, -1));
    for (size_t i = 0; i < doc.GetRowCount(); i++)
    {
        std::string section_name = doc.GetCell<std::string>("Section", i);
        std::string item_name = doc.GetCell<std::string>("Dish", i);
        int item_price = doc.GetCell<int>("Price", i);
        std::string ingredients_string = doc.GetCell<std::string>("Ingredients", i);
        I item(item_name, item_price, parse_ingredient_list<In>(ingredients_string));
        menu.add_menu_item_to_menu_section(item, section_name);
    }
}

void read_tables_from_csv(std::string file_path, std::map<uint32_t, Table> &tables)
{
    rapidcsv::Document doc(file_path, rapidcsv::LabelParams(0, -1));
    for (size_t i = 0; i < doc.GetRowCount(); i++)
    {
        uint32_t table_id = doc.GetCell<uint32_t>("Table_id", i);
        uint32_t num_of_seats = doc.GetCell<uint32_t>("Seats", i);
        tables[table_id] = Table{num_of_seats};
    }
}