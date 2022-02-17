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
    errorStr.append(" (excluding comments) doesn't exist");
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
            errorStr.append(" (excluding comments)");
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
        errorStr.append(" (excluding comments)");
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

void NanoParser::checkLinksLine(size_t index)
{
    std::string errorStr;
    std::string firstName;
    std::string firstValue;
    std::string secondName;
    std::string secondValue;

    if (!std::regex_match(_fileContent[index], std::regex("([a-z0-9_]+)([:])([0-9]+)([ \t])([a-z0-9_]+)([:])([0-9]+)"))) {
        errorStr = "Wrong format for the creation of a links in line ";
        errorStr.append(std::to_string(index + 2));
        errorStr.append(" (excluding comments)");
        throw NanoError(errorStr);
    }
    firstName = getNameFromNameValue(getComponentTypeFromLine(index));
    firstValue = getValueFromNameValue(getComponentTypeFromLine(index));
    //checkComponentType(componentType, index);
    secondName = getNameFromNameValue(getComponentNameFromLine(index));
    secondValue = getValueFromNameValue(getComponentNameFromLine(index));
    //checkComponentName(componentName, index);
    std::cout << firstName << " " << firstValue << " " << secondName << " " << secondValue << std::endl;
    _links.push_back(std::make_tuple(firstName, firstValue, secondName, secondValue));
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
    //for (int i = 1; i < _fileContent.size(); i++)
        //if (true) //check if .chipset line is valid

}