#include <iostream>
#include "menu.hpp"

std::string format_price(int price)
{
    int price_in_zl = price / 100;
    int price_in_gr = price % 100;
    return std::to_string(price_in_zl) + "." + std::to_string(price_in_gr);
}

void add_ingredients_to_dish(Dish &dish)
{
    while (true)
    {
        try
        {
            std::string ingredient_name;
            std::string ingredient_calories_str;
            std::cout << "Wprowadź nazwę składnika lub napisz 'k' aby dodać danie do sekcji: ";
            std::cin >> ingredient_name;
            if (ingredient_name == "k")
                break;
            std::cout << "Wprowadź wartość kaloryczną składnika: ";
            std::cin >> ingredient_calories_str;
            Ingredient ingredient(ingredient_name, std::stoi(ingredient_calories_str));
            dish.add_ingredient(ingredient);
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << std::endl;
            std::cout << "wprowadzono błędną wartość kaloryczną" << std::endl;
            std::cout << std::endl;
        }
    }
}

void add_dish_to_section(MenuSection &section)
{
    while (true)
    {
        try
        {
            std::string answer;
            std::string prompt = "Wprowadź nazwę dania lub napisz 'k', aby wyjść: ";
            std::cout << prompt;
            std::getline(std::cin, answer);
            if (answer == "k")
                break;
            std::string price_string;
            std::cout << "Wprowadź cenę dania (w groszach): ";
            std::cin >> price_string;
            std::cin.ignore();
            Dish dish(answer, std::stoi(price_string), {});
            add_ingredients_to_dish(dish);
            section.add_dish(dish);
            std::cin.ignore();
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << std::endl;
            std::cout << "wprowadzono błędną cenę" << std::endl;
            std::cout << std::endl;
        }
    }
}

void ask_if_add(std::list<MenuSection> &sections)
{
    while (true)
    {
        bool is_valid = false;
        std::string answer;
        std::string prompt = "Wprowadź nazwę sekcji do której chcesz dodać danie lub napisz 'k', aby wyświetlić menu (Przystawki/Zupy/Dania główne/Desery): ";
        std::cout << prompt;
        std::getline(std::cin, answer);
        if (answer == "k")
            break;
        for (auto &section : sections)
        {
            if (section.get_name() == answer)
            {
                add_dish_to_section(section);
                is_valid = true;
                break;
            }
        }
        if (!is_valid)
        {
            std::cout << std::endl;
            std::cout << "Nie znaleziono sekcji o podanej nazwie" << std::endl;
            std::cout << std::endl;
        }
    }
}

void print_menu(Menu &menu)
{
    std::cout << "Menu: " << std::endl;
    for (MenuSection menu_section : menu.get_menu_sections())
    {
        std::cout << std::endl;
        std::cout << "  " << menu_section.get_name() << ":" << std::endl;
        for (Dish dish : menu_section.get_dishes())
        {
            std::cout << std::endl;
            std::cout << "  - " << dish.get_name() << "\t" << format_price(dish.get_price()) << " PLN, " << dish.get_total_calories() << " kcal" << std::endl;
            for (Ingredient ingredient : dish.get_ingredients())
                std::cout << "     * " << ingredient.get_name() << std::endl;
        }
    }
}

int main()
{
    Menu menu("Menu");
    Ingredient lamb("baranina", 300);
    Ingredient salat("sałata", 20);
    Ingredient chicken("kurczak", 200);
    Ingredient rice("ryż", 200);
    Ingredient tomatoe("pomidor", 30);
    Ingredient feta_cheese("ser feta", 60);
    Ingredient onoin("cebula", 45);
    Ingredient chocolate("czekolada", 240);
    Ingredient cream("śmietana", 120);

    std::list<Ingredient> greek_salad_ingreds = {salat, tomatoe, feta_cheese, onoin};
    Dish greek_salad("Sałatka grecka", 1800, greek_salad_ingreds);

    std::list<Ingredient> kebab_ingreds = {lamb, chicken, salat, tomatoe, onoin};
    Dish kebab("Kebab mieszany", 1600, kebab_ingreds);

    std::list<Ingredient> tomatoe_soup_ingreds = {tomatoe, rice};
    Dish tomatoe_soup("Zupa pomidorowa", 1200, tomatoe_soup_ingreds);

    std::list<Ingredient> chocolate_ice_cream_ingreds = {chocolate, cream};
    Dish chocolate_ice_cream("Lody czekoladowe", 1400, chocolate_ice_cream_ingreds);

    MenuSection appetisers("Przystawki");
    appetisers.add_dish(greek_salad);

    MenuSection soups("Zupy");
    soups.add_dish(tomatoe_soup);

    MenuSection main_dishes("Dania główne");
    main_dishes.add_dish(kebab);

    MenuSection desserts("Desery");
    desserts.add_dish(chocolate_ice_cream);

    menu.add_menu_section(appetisers);
    menu.add_menu_section(soups);
    menu.add_menu_section(main_dishes);
    menu.add_menu_section(desserts);

    ask_if_add(menu.get_menu_sections());

    print_menu(menu);
}