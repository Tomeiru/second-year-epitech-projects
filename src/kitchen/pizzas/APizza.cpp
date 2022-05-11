/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** APizza
*/

#include "APizza.hpp"
#include "Regina.hpp"
#include "Margarita.hpp"
#include "Americana.hpp"
#include "Fantasia.hpp"

plazza::APizza::APizza(uint64_t id, plazza::IPizza::PizzaSize size)
    : _id(id), _type(PizzaType::MARGARITA), _size(size), _cookTime(1)
{
    _id = id;
    _type = MARGARITA;
    _size = size;
    _cookTime = 1;
}

plazza::APizza::~APizza()
{
}

plazza::IPizza::PizzaType plazza::APizza::getType() const
{
    return (_type);
}

std::string plazza::APizza::getStringType() const
{
    return (pizzaTypeToString(_type));
}

plazza::IPizza::PizzaSize plazza::APizza::getSize() const
{
    return (_size);
}

std::string plazza::APizza::getStringSize() const
{
    return (pizzaSizeToString(_size));
}

const std::vector<plazza::IPizza::Ingredient> &plazza::APizza::getIngredients() const
{
    return (_ingredients);
}

float plazza::APizza::getCookTime() const
{
    return (_cookTime);
}

std::string plazza::APizza::getIngredientList() const
{
    std::string ret = "";

    for (unsigned int i = 0; i < _ingredients.size(); i++) {
        ret.append("- ");
        ret.append(ingredientToString(_ingredients[i]));
        ret.append(".\n");
    }
    return (ret);
}

plazza::IPizza::PizzaType plazza::APizza::stringToPizzaType(std::string type)
{
    static std::map<std::string, plazza::IPizza::PizzaType> typeMap = {
        std::make_pair("regina", plazza::IPizza::REGINA),
        std::make_pair("margarita", plazza::IPizza::MARGARITA),
        std::make_pair("americana", plazza::IPizza::AMERICANA),
        std::make_pair("fantasia", plazza::IPizza::FANTASIA),
    };
    std::map<std::string, plazza::IPizza::PizzaType>::iterator it = typeMap.find(type);

    if (it != typeMap.end())
        return (it->second);
    throw std::exception();
}

plazza::IPizza::PizzaSize plazza::APizza::stringToPizzaSize(std::string size)
{
    static std::map<std::string, plazza::IPizza::PizzaSize> sizeMap = {
        std::make_pair("S", plazza::IPizza::S),
        std::make_pair("M", plazza::IPizza::M),
        std::make_pair("L", plazza::IPizza::L),
        std::make_pair("XL", plazza::IPizza::XL),
        std::make_pair("XXL", plazza::IPizza::XXL),
    };
    std::map<std::string, plazza::IPizza::PizzaSize>::iterator it = sizeMap.find(size);

    if (it != sizeMap.end())
        return (it->second);
    throw std::exception();
}

std::string plazza::APizza::pizzaTypeToString(plazza::IPizza::PizzaType type)
{
    static std::map<plazza::IPizza::PizzaType, std::string> typeMap = {
        std::make_pair(plazza::IPizza::REGINA, "regina"),
        std::make_pair(plazza::IPizza::MARGARITA, "margarita"),
        std::make_pair(plazza::IPizza::AMERICANA, "americana"),
        std::make_pair(plazza::IPizza::FANTASIA, "fantasia"),
    };
    std::map<plazza::IPizza::PizzaType, std::string>::iterator it = typeMap.find(type);

    if (it != typeMap.end())
        return (it->second);
    throw std::exception();
}

std::string plazza::APizza::pizzaSizeToString(plazza::IPizza::PizzaSize size)
{
    static std::map<plazza::IPizza::PizzaSize, std::string> sizeMap = {
        std::make_pair(plazza::IPizza::S, "S"),
        std::make_pair(plazza::IPizza::M, "M"),
        std::make_pair(plazza::IPizza::L, "L"),
        std::make_pair(plazza::IPizza::XL, "XL"),
        std::make_pair(plazza::IPizza::XXL, "XXL"),
    };
    std::map<plazza::IPizza::PizzaSize, std::string>::iterator it = sizeMap.find(size);

    if (it != sizeMap.end())
        return (it->second);
    throw std::exception();
}

std::string plazza::APizza::ingredientToString(plazza::IPizza::Ingredient ingredient)
{
    static std::map<plazza::IPizza::Ingredient, std::string> ingredientMap = {
        std::make_pair(plazza::IPizza::DOE, "Doe"),
        std::make_pair(plazza::IPizza::TOMATO, "Tomato"),
        std::make_pair(plazza::IPizza::GRUYERE, "Gruyere"),
        std::make_pair(plazza::IPizza::HAM, "Ham"),
        std::make_pair(plazza::IPizza::MUSHROOMS, "Mushrooms"),
        std::make_pair(plazza::IPizza::STEAK, "Steak"),
        std::make_pair(plazza::IPizza::EGGPLANT, "Eggplant"),
        std::make_pair(plazza::IPizza::GOAT_CHEESE, "Goat cheese"),
        std::make_pair(plazza::IPizza::CHIEF_LOVE, "Chief love"),
    };

    std::map<plazza::IPizza::Ingredient, std::string>::iterator it = ingredientMap.find(ingredient);

    if (it != ingredientMap.end())
        return (it->second);
    throw std::exception();
}

std::unique_ptr<plazza::IPizza> plazza::APizza::pizzaFactory(uint64_t id, PizzaType type, PizzaSize size)
{
    static std::map<PizzaType, std::function<std::unique_ptr<IPizza>(uint64_t, PizzaSize)>> factoryList {
        std::make_pair(REGINA, [](uint64_t id, PizzaSize sizeArg) {return std::make_unique<Regina>(id, sizeArg);}),
        std::make_pair(MARGARITA, [](uint64_t id, PizzaSize sizeArg) {return std::make_unique<Margarita>(id, sizeArg);}),
        std::make_pair(AMERICANA, [](uint64_t id, PizzaSize sizeArg) {return std::make_unique<Regina>(id, sizeArg);}),
        std::make_pair(FANTASIA, [](uint64_t id, PizzaSize sizeArg) {return std::make_unique<Regina>(id, sizeArg);})
    };
    std::map<PizzaType, std::function<std::unique_ptr<IPizza>(uint64_t, PizzaSize)>>::iterator it = factoryList.find(type);

    if (it != factoryList.end())
        return ((it->second)(id, size));
    throw std::exception();
}

std::unique_ptr<plazza::IPizza> plazza::APizza::pizzaFactory(uint64_t id, std::string typeStr, std::string sizeStr)
{
    PizzaType type = plazza::APizza::stringToPizzaType(typeStr);
    PizzaSize size  = plazza::APizza::stringToPizzaSize(sizeStr);

    return pizzaFactory(id, type, size);
}
