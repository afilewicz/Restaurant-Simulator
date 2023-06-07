#pragma once
#include <string>

class Ingredient
{
private:
    std::string name_ = "";
    int calories_ = 0;

public:
    Ingredient() = default;
    Ingredient(std::string name, float calories);
    std::string get_name() const;
    void set_name(const std::string new_name);
    float get_calories() const;
    void set_calories(const float new_calories);
    bool operator==(const Ingredient &ingredient) const;
};
