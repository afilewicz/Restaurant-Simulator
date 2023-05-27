#include "dish.hpp"
#include <stdexcept>
#include <algorithm>
#include <numeric>

Dish::Dish(std::string name, int price, std::list<Ingredient> ingredients)
{
    if (name.empty())
        throw std::invalid_argument("Name can not be empty");
    name_ = name;
    if (price < 0)
        throw std::invalid_argument("Price can not be negative.");
    price_ = price;
    ingredients_ = ingredients;
}

std::string Dish::get_name() const
{
    return name_;
}

void Dish::set_name(const std::string new_name)
{
    if (new_name.empty())
        throw std::invalid_argument("Name can not be empty");
    name_ = new_name;
}

int Dish::get_price() const
{
    return price_;
}

void Dish::set_price(const int new_price)
{
    if (new_price < 0)
        throw std::invalid_argument("Price can not be negative.");
    price_ = new_price;
}

float Dish::get_total_calories() const
{
    return std::accumulate(ingredients_.begin(), ingredients_.end(), 0.0f, [](float sum, const Ingredient &ingredient)
                           { return sum + ingredient.get_calories(); });
}

const std::list<Ingredient> &Dish::get_ingredients() const
{
    return ingredients_;
}

void Dish::add_ingredient(Ingredient &new_ingredient)
{
    ingredients_.push_back(new_ingredient);
}

void Dish::remove_ingredient(Ingredient &ingredient_to_remove)
{
    if (ingredients_.empty())
        throw std::logic_error("Can not remove ingredient from epmty list.");
    if (!is_ingredient_in_list(ingredient_to_remove))
        throw std::invalid_argument("ingredient_to_remove not in ingredients list.");
    ingredients_.remove(ingredient_to_remove);
}

bool Dish::is_ingredient_in_list(Ingredient &ingredient_to_remove) const
{
    return (std::find(ingredients_.begin(), ingredients_.end(), ingredient_to_remove) != ingredients_.end());
}

bool Dish::operator==(const Dish &other_dish) const
{
    return name_ == other_dish.name_;
}
