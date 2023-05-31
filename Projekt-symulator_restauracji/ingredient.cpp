#include "ingredient.hpp"
#include <stdexcept>

Ingredient::Ingredient(std::string name, float calories) : name_(name), calories_(calories)
{
    if (name.empty())
        throw std::invalid_argument("Name can not be empty");
    else if (calories < 0)
        throw std::invalid_argument("Calories can not be negative");
}

std::string Ingredient::get_name() const
{
    return name_;
}

void Ingredient::set_name(const std::string new_name)
{
    if (new_name.empty())
        throw std::invalid_argument("Name can not be empty");
    name_ = new_name;
}

float Ingredient::get_calories() const
{
    return calories_;
}

void Ingredient::set_calories(const float new_calories)
{
    if (new_calories < 0)
        throw std::invalid_argument("Calories can not be negative");
    calories_ = new_calories;
}

bool Ingredient::operator==(const Ingredient &other_ingredient) const
{
    return name_ == other_ingredient.name_;
}
