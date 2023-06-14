#pragma once
#include <string>
#include <list>
#include "rapidcsv.h"

template <typename Ingredient>
std::list<Ingredient> parse_ingredient_list(std::string ingredient_string)
{
    std::list<Ingredient> result;
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

template <typename MenuItem, typename Menu, typename Ingredient>
void read_from_csv(std::string file_path, Menu &menu)
{
    rapidcsv::Document doc(file_path, rapidcsv::LabelParams(0, -1));
    for (size_t i = 0; i < doc.GetRowCount(); i++)
    {
        std::string section_name = doc.GetCell<std::string>("Section", i);
        std::string item_name = doc.GetCell<std::string>("Dish", i);
        int item_price = doc.GetCell<int>("Price", i);
        std::string ingredients_string = doc.GetCell<std::string>("Ingredients", i);
        MenuItem item(item_name, item_price, parse_ingredient_list<Ingredient>(ingredients_string));
        menu.add_menu_item_to_menu_section(item, section_name);
    }
}
