// #include <iostream>
// #include "menu.hpp"

// std::string format_price(int price)
// {
//     int price_in_zl = price / 100;
//     int price_in_gr = price % 100;
//     return std::to_string(price_in_zl) + "." + std::to_string(price_in_gr);
// }

// void add_ingredients_to_menuitem(MenuItem &menuitem)
// {
//     while (true)
//     {
//         try
//         {
//             std::string ingredient_name;
//             std::string ingredient_calories_str;
//             std::cout << "Wprowadź nazwę składnika lub napisz 'k' aby dodać danie do sekcji: ";
//             std::cin >> ingredient_name;
//             if (ingredient_name == "k")
//                 break;
//             std::cout << "Wprowadź wartość kaloryczną składnika: ";
//             std::cin >> ingredient_calories_str;
//             Ingredient ingredient(ingredient_name, std::stoi(ingredient_calories_str));
//             menuitem.add_ingredient(ingredient);
//         }
//         catch (const std::invalid_argument &e)
//         {
//             std::cout << std::endl;
//             std::cout << "wprowadzono błędną wartość kaloryczną" << std::endl;
//             std::cout << std::endl;
//         }
//     }
// }

// void add_menuitem_to_section(MenuSection &section)
// {
//     while (true)
//     {
//         try
//         {
//             std::string answer;
//             std::string prompt = "Wprowadź nazwę dania lub napisz 'k', aby wyjść: ";
//             std::cout << prompt;
//             std::getline(std::cin, answer);
//             if (answer == "k")
//                 break;
//             std::string price_string;
//             std::cout << "Wprowadź cenę dania (w groszach): ";
//             std::cin >> price_string;
//             std::cin.ignore();
//             MenuItem menuitem(answer, std::stoi(price_string), {});
//             add_ingredients_to_menuitem(menuitem);
//             section.add_menuitem(menuitem);
//             std::cin.ignore();
//         }
//         catch (const std::invalid_argument &e)
//         {
//             std::cout << std::endl;
//             std::cout << "wprowadzono błędną cenę" << std::endl;
//             std::cout << std::endl;
//         }
//     }
// }

// void ask_if_add(std::list<MenuSection> &sections)
// {
//     while (true)
//     {
//         bool is_valid = false;
//         std::string answer;
//         std::string prompt = "Wprowadź nazwę sekcji do której chcesz dodać danie lub napisz 'k', aby wyświetlić menu (Przystawki/Zupy/Dania główne/Desery): ";
//         std::cout << prompt;
//         std::getline(std::cin, answer);
//         if (answer == "k")
//             break;
//         for (auto &section : sections)
//         {
//             if (section.get_name() == answer)
//             {
//                 add_menuitem_to_section(section);
//                 is_valid = true;
//                 break;
//             }
//         }
//         if (!is_valid)
//         {
//             std::cout << std::endl;
//             std::cout << "Nie znaleziono sekcji o podanej nazwie" << std::endl;
//             std::cout << std::endl;
//         }
//     }
// }

// void print_menu(Menu &menu)
// {
//     std::cout << "Menu: " << std::endl;
//     for (MenuSection menu_section : menu.get_menu_sections())
//     {
//         std::cout << std::endl;
//         std::cout << "  " << menu_section.get_name() << ":" << std::endl;
//         for (MenuItem menuitem : menu_section.get_menuitems())
//         {
//             std::cout << std::endl;
//             std::cout << "  - " << menuitem.get_name() << "\t" << format_price(menuitem.get_price()) << " PLN, " << menuitem.get_total_calories() << " kcal" << std::endl;
//             for (Ingredient ingredient : menuitem.get_ingredients())
//                 std::cout << "     * " << ingredient.get_name() << std::endl;
//         }
//     }
// }

// int main()
// {
//     Menu menu("Menu");
//     Ingredient lamb("baranina", 300);
//     Ingredient salat("sałata", 20);
//     Ingredient chicken("kurczak", 200);
//     Ingredient rice("ryż", 200);
//     Ingredient tomatoe("pomidor", 30);
//     Ingredient feta_cheese("ser feta", 60);
//     Ingredient onoin("cebula", 45);
//     Ingredient chocolate("czekolada", 240);
//     Ingredient cream("śmietana", 120);

//     std::list<Ingredient> greek_salad_ingreds = {salat, tomatoe, feta_cheese, onoin};
//     MenuItem greek_salad("Sałatka grecka", 1800, greek_salad_ingreds);

//     std::list<Ingredient> kebab_ingreds = {lamb, chicken, salat, tomatoe, onoin};
//     MenuItem kebab("Kebab mieszany", 1600, kebab_ingreds);

//     std::list<Ingredient> tomatoe_soup_ingreds = {tomatoe, rice};
//     MenuItem tomatoe_soup("Zupa pomidorowa", 1200, tomatoe_soup_ingreds);

//     std::list<Ingredient> chocolate_ice_cream_ingreds = {chocolate, cream};
//     MenuItem chocolate_ice_cream("Lody czekoladowe", 1400, chocolate_ice_cream_ingreds);

//     MenuSection appetisers("Przystawki");
//     appetisers.add_menuitem(greek_salad);

//     MenuSection soups("Zupy");
//     soups.add_menuitem(tomatoe_soup);

//     MenuSection main_menuitems("Dania główne");
//     main_menuitems.add_menuitem(kebab);

//     MenuSection desserts("Desery");
//     desserts.add_menuitem(chocolate_ice_cream);

//     menu.add_menu_section(appetisers);
//     menu.add_menu_section(soups);
//     menu.add_menu_section(main_menuitems);
//     menu.add_menu_section(desserts);

//     ask_if_add(menu.get_menu_sections());

//     print_menu(menu);
// }