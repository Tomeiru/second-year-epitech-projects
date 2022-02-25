/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** NanoParser
*/

#include "NanoParser.hpp"

NanoParser::NanoParser()
{
}

NanoParser::~NanoParser()
{
}

void NanoParser::argumentCheck(int ac)
{
    std::string errorStr;

    if (ac != 2) {
        errorStr = "Wrong number of arguments! (Got ";
        errorStr.append(std::to_string(ac));
        errorStr.append(" instead of 2)");
        throw NanoError(errorStr);
    }
}

void NanoParser::openFile(char *filepath)
{
    std::string line;
    std::ifstream content(filepath);
    std::string delims(" \t");

    if (!content.is_open())
        throw NanoError("Cannot open file passed as parameter");
    while (std::getline(content, line))
        if (line != "" && line[line.find_first_not_of(delims)] != '#') {
            if (line.find('#') != std::string::npos)
                line.resize(line.find_first_of('#'));
            line.resize(line.find_last_not_of(delims) + 1);
            _fileContent.push_back(line);
        }
}

std::vector<std::string> NanoParser::getFileContent(void)
{
    return (_fileContent);
}

void NanoParser::displayFileContent(void)
{
    for (size_t i = 0; i < _fileContent.size(); i++)
        std::cout << _fileContent[i] << std::endl;
}

void NanoParser::checkEmptyFile(void)
{
    if (_fileContent.size() == 0)
        throw NanoError("File passed as parameter is empty");
}

std::string NanoParser::getComponentTypeFromLine(size_t index)
{
    std::string ret = _fileContent[index];

    ret.resize(ret.find_first_of(" \t"));
    return (ret);
}

void NanoParser::checkComponentType(std::string componentType, size_t index)
{
    std::string errorStr;
    std::vector <std::string> componentList = {
        "input", "clock", "true", "false", "output", "4001", "4011", "4030",
        "4071", "4081", "4069", "4008", "4013", "4017", "4040", "4094", "4512",
        "4514", "4801", "2716", "logger"
    };
    for (size_t i = 0; i < componentList.size(); i++)
        if (componentList[i] == componentType)
            return;
    errorStr = "The component specified for the creation of a chipset in line ";
    errorStr.append(std::to_string(index + 1));
    errorStr.append(" (excluding comments and empty lines) doesn't exist");
    throw NanoError(errorStr);
}

std::string NanoParser::getComponentNameFromLine(size_t index)
{
    std::string ret = _fileContent[index];

    ret.erase(0, ret.find_first_of(" \t") + 1);
    return (ret);
}

void NanoParser::checkComponentName(std::string componentName, size_t index)
{
    std::string errorStr;

    for (size_t i = 1; i < index; i++) {
        if (componentName == std::get<1>(_chipsets[i - 1])) {
            errorStr = "Name of component already exists for the creation of a chipset in line ";
            errorStr.append(std::to_string(index + 1));
            errorStr.append(" (excluding comments and empty lines)");
            throw NanoError(errorStr);
        }
    }
}

void NanoParser::checkChipsetLine(size_t index)
{
    std::string errorStr;
    std::string componentType;
    std::string componentName;

    if (!std::regex_match(_fileContent[index], std::regex("([a-z0-9]+)([ \t])([a-z0-9_]+)"))) {
        errorStr = "Wrong format for the creation of a chipset in line ";
        errorStr.append(std::to_string(index + 1));
        errorStr.append(" (excluding comments and empty lines)");
        throw NanoError(errorStr);
    }
    componentType = getComponentTypeFromLine(index);
    checkComponentType(componentType, index);
    componentName = getComponentNameFromLine(index);
    checkComponentName(componentName, index);
    _chipsets.push_back(std::make_tuple(componentType, componentName));
}

void NanoParser::checkChipsetField(void)
{
    if (_fileContent.size() == 1)
        throw NanoError("File passed as parameter cannot have a correct chipset field (Length not long enough)");
    if (_fileContent[0] != ".chipsets:")
        throw NanoError("File passed as parameter doesn't contain a \".chipsets:\" field or it isn't the first thing in the file");
    for (size_t i = 1; i < _fileContent.size() && _fileContent[i] != ".links:"; i++)
        checkChipsetLine(i);
}

std::string NanoParser::getNameFromNameValue(std::string NameValue)
{
    std::string ret = NameValue;

    ret.resize(ret.find_first_of(":"));
    return (ret);
}

std::string NanoParser::getValueFromNameValue(std::string NameValue)
{
    std::string ret = NameValue;

    ret.erase(0, ret.find_first_of(":") + 1);
    return (ret);
}

void NanoParser::checkLinksName(std::string name, size_t index, bool first)
{
    std::string errorStr;

    for (size_t i = 0; i < _chipsets.size(); i++)
        if (name == std::get<1>(_chipsets[i]))
            return;
    if (first == true)
        errorStr = "Name in the first link doesn't correspond to an existing component in line ";
    else
        errorStr = "Name in the second link doesn't correspond to an existing component in line ";
    errorStr.append(std::to_string(index + 1));
    errorStr.append(" (excluding comments and empty lines)");
    throw NanoError(errorStr);
}

std::vector<std::tuple<std::string, size_t>> NanoParser::generateComponentPin(void)
{
    std::vector<std::tuple<std::string, size_t>> ret;

    ret.push_back(std::make_tuple("input", 1));
    ret.push_back(std::make_tuple("clock", 1));
    ret.push_back(std::make_tuple("true", 1));
    ret.push_back(std::make_tuple("false", 1));
    ret.push_back(std::make_tuple("output", 1));
    ret.push_back(std::make_tuple("4001", 14));
    ret.push_back(std::make_tuple("4011", 14));
    ret.push_back(std::make_tuple("4030", 14));
    ret.push_back(std::make_tuple("4071", 14));
    ret.push_back(std::make_tuple("4081", 14));
    ret.push_back(std::make_tuple("4069", 14));
    ret.push_back(std::make_tuple("4008", 16));
    ret.push_back(std::make_tuple("4013", 14));
    ret.push_back(std::make_tuple("4017", 16));
    ret.push_back(std::make_tuple("4040", 16));
    ret.push_back(std::make_tuple("4094", 16));
    ret.push_back(std::make_tuple("4512", 16));
    ret.push_back(std::make_tuple("4514", 24));
    ret.push_back(std::make_tuple("4801", 24));
    ret.push_back(std::make_tuple("2716", 24));
    ret.push_back(std::make_tuple("logger", 10));
    return (ret);
}

void NanoParser::checkLinksValue(std::string name, size_t value, size_t index, bool first)
{
    std::string errorStr;
    size_t i = 0;
    size_t l = 0;
    bool error = false;
    static std::vector<std::tuple<std::string, size_t>> list = generateComponentPin();

    for ( ; i < _chipsets.size(); i++)
        if (name == std::get<1>(_chipsets[i]))
            break;
    for ( ; l < list.size(); l++)
        if (std::get<0>(_chipsets[i]) == std::get<0>(list[l]))
            break;
    if (std::get<1>(list[l]) == 1) {
        if (value != 1)
            error = true;
    }
    else if (std::get<1>(list[l]) == 10) {
        if (value == 0 || value > 10)
            error = true;
    }
    else if (value == 0 || value >= std::get<1>(list[l]) || value == std::get<1>(list[l]) / 2)
        error = true;
    if (error == true) {
        if (first == true)
            errorStr = "Value in the first link isn't a correct value in line ";
        else
            errorStr = "Value in the second link isn't a correct value in line ";
        errorStr.append(std::to_string(index + 1));
        errorStr.append(" (excluding comments and empty lines)");
        throw NanoError(errorStr);
    }
}

void NanoParser::checkLinksLine(size_t index)
{
    std::string errorStr;
    std::string firstName;
    size_t firstValue;
    std::string secondName;
    size_t secondValue;

    if (!std::regex_match(_fileContent[index], std::regex("([a-z0-9_]+)([:])([0-9]+)([ \t])([a-z0-9_]+)([:])([0-9]+)"))) {
        errorStr = "Wrong format for the creation of a links in line ";
        errorStr.append(std::to_string(index + 2));
        errorStr.append(" (excluding comments and empty lines)");
        throw NanoError(errorStr);
    }
    firstName = getNameFromNameValue(getComponentTypeFromLine(index));
    checkLinksName(firstName, index, true);
    firstValue = std::stol(getValueFromNameValue(getComponentTypeFromLine(index)));
    checkLinksValue(firstName, firstValue, index, true);
    secondName = getNameFromNameValue(getComponentNameFromLine(index));
    checkLinksName(secondName, index, false);
    secondValue = std::stol(getValueFromNameValue(getComponentNameFromLine(index)));
    checkLinksValue(secondName, secondValue, index, false);
    _links.push_back(std::make_tuple(firstName, firstValue, secondName, secondValue));
}

std::vector<std::tuple<std::string, std::string>> NanoParser::getChipsetVec(void)
{
    return (_chipsets);
}

void NanoParser::checkLinksField(void)
{
    if (_fileContent.size() - _chipsets.size() <= 2)
        throw NanoError("File passed as parameter cannot have a correct links field (Length not long enough)");
    if (_fileContent[_chipsets.size() + 1] != ".links:")
        throw NanoError("File passed as parameter doesn't contain a \".links:\" field or it isn't the first thing after the \".chipsets:\" field in the file");
    for (size_t i = _chipsets.size() + 2; i < _fileContent.size(); i++)
        checkLinksLine(i);
}



void NanoParser::checkFileContent(void)
{
    checkEmptyFile();
    checkChipsetField();
    checkLinksField();
}