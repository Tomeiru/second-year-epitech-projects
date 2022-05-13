/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Reception
*/

#include "Reception.hpp"

Reception::Reception(std::vector<std::unique_ptr<plazza::IPizza>> *queue)
{
    _input = "";
    _delims = " \t";
    _queue = queue;
}

Reception::~Reception()
{
}

void Reception::getInput()
{
    std::getline(std::cin, _input);
    if (std::cin.eof())
        throw std::exception();
}

bool Reception::checkEmpty()
{
    if (_input == "")
        return (true);
    if (_input.find_last_not_of(_delims) == std::string::npos)
        return (true);
    return (false);
}

std::string Reception::removeSpacesBeforeAndAfter(std::string string)
{
    string.resize(string.find_last_not_of(_delims) + 1);
    std::size_t pos = string.find_first_not_of(_delims);
    if (pos != 0)
        string.erase(0, string.find_first_not_of(_delims));
    return (string);
}

void Reception::handleOrders()
{
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
            throw std::exception();
        for (unsigned int i = 0; i < pizzaList.size(); i++) {
            if (pizzaList[i] == match[1])
                break;
            if (i + 1 == pizzaList.size())
                throw std::exception();
        }
        for (int i = 0; i < std::stol(match[6].str()); i++)
            _order.push_back(plazza::APizza::pizzaFactory(pizzaId++, match[1].str(), match[3].str()));
        std::cout << match[1].str() << " " << match[3].str() << " " << match[6].str() << std::endl;
    }
    for (unsigned int i = 0; i < _order.size(); i++) {
        std::cout << _order[i] << std::endl;
        _queue->push_back(std::move(_order[i]));
    }
}

void Reception::handleInput()
{
    if (checkEmpty())
        return;
    _input = removeSpacesBeforeAndAfter(_input);
    if (_input == "status") {
        std::cout << "TODO: Call the status function" << std::endl;
        return;
    }try {
        handleOrders();
    }catch (...) {
        std::cerr << "Command does not exist or Order is ill-formated" << std::endl;
        return;
    }
}

void Reception::console()
{
    while (1) {
        std::cout << "Enter a command or an order: ";
        try {
            getInput();
        }
        catch (...) {
            break;
        }
        handleInput();
        _input = "";
        _order.clear();
    }
}

void *Reception::handleReceivedPizza(void *arg)
{
    return (nullptr);
}
