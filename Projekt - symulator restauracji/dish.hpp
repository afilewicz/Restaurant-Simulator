#pragma once
#include <list>
#include <string>
#include "ingredient.hpp"

class Dish
{
private:
    std::string name_;
    int price_;
    std::list<Ingredient> ingredients_;
    bool is_ingredient_in_list(Ingredient &ingredient_to_remove) const;

public:
    Dish(std::string name, int price, std::list<Ingredient> ingredients);
    std::string get_name() const;
    void set_name(const std::string new_name);
    int get_price() const;
    void set_price(const int new_price);
    float get_total_calories() const;
    const std::list<Ingredient> &get_ingredients() const;
    void add_ingredient(Ingredient &new_ingredient);
    void remove_ingredient(Ingredient &ingredient_to_remove);
    bool operator==(const Dish &other_dish) const;
};