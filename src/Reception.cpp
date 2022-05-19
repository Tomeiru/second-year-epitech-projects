/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Reception
*/

#include "Reception.hpp"

void plazza::Reception::getInput()
{
    std::getline(std::cin, _input);
    if (std::cin.eof())
        throw std::exception();
}

bool plazza::Reception::checkEmpty()
{
    if (_input == "")
        return (true);
    if (_input.find_last_not_of(_delims) == std::string::npos)
        return (true);
    return (false);
}

std::string plazza::Reception::removeSpacesBeforeAndAfter(std::string string)
{
    string.resize(string.find_last_not_of(_delims) + 1);
    std::size_t pos = string.find_first_not_of(_delims);
    if (pos != 0)
        string.erase(0, string.find_first_not_of(_delims));
    return (string);
}

void plazza::Reception::handleOrders()
{
    static uint64_t orderId = 0;
    static uint64_t pizzaId = 0;
    std::cout << _input << std::endl;
    std::string line;
    std::stringstream ss(_input);
    std::vector<std::string> pizzaList = {
        "regina", "margarita", "americana", "fantasia"
    };
    std::vector<std::string> words;

    while(std::getline(ss, line, ';'))
        words.push_back(line);
    for (unsigned int i = 0; i < words.size(); i++) {
        words[i] = removeSpacesBeforeAndAfter(words[i]);
        std::smatch match;
        if (!std::regex_search(words[i], match, std::regex("([a-zA-Z]+)([ \t]+)(S|M|L|XL|XXL)([ \t]+)(x)([1-9][0-9]*)")))
            throw InvalidOrder();
        for (unsigned int i = 0; i < pizzaList.size(); i++) {
            if (pizzaList[i] == match[1])
                break;
            if (i + 1 == pizzaList.size())
                throw InvalidOrder();
        }
        for (int i = 0; i < std::stol(match[6].str()); i++)
            _pizzas.push_back(plazza::APizza::pizzaFactory(pizzaId++, match[1].str(), match[3].str()));
        // std::cout << match[1].str() << " " << match[3].str() << " " << match[6].str() << std::endl;
    }
    std::cout << "Order " << orderId << " created" << std::endl;
    _order = std::make_unique<plazza::Order>(orderId++);
    for (unsigned int i = 0; i < _pizzas.size(); i++) {
        // std::cout << _pizzas[i] << std::endl;
        _order->addPizzaToOrder(std::move(_pizzas[i]));
    }
    _logistic->addNewOrder(std::move(_order));
}

void plazza::Reception::handleInput()
{
    if (checkEmpty())
        return;
    _input = removeSpacesBeforeAndAfter(_input);
    if (_input == "status")
        return (_logistic->toggleStatus());
    try {
        handleOrders();
    }catch (InvalidOrder &e) {
        std::cerr << "Command does not exist or Order is ill-formated" << std::endl;
        return;
    }
}

void plazza::Reception::console()
{
    while (1) {
        std::cout << "Enter a command or an order: ";
        try {
            getInput();
        }
        catch (...) {
            _logistic->toggleEnd();
            break;
        }
        handleInput();
        _input = "";
        _order = nullptr;
        _pizzas.clear();
    }
}

void *plazza::Reception::handleReceivedPizza(void *arg)
{
    return (nullptr);
}
