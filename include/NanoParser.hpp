/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** NanoParser
*/

#ifndef NANOPARSER_HPP_
#define NANOPARSER_HPP_

#include "NanoError.hpp"

class NanoParser {
    public:
        NanoParser();
        ~NanoParser();
        void argumentCheck(int ac);
        void openFile(char *filepath);
        std::vector<std::string> getFileContent(void);
        void displayFileContent(void);
        void checkFileContent(void);
        void checkEmptyFile(void);
        void checkChipsetField(void);
        void checkChipsetLine(size_t index);
        std::string getComponentTypeFromLine(size_t index);
        void checkComponentType(std::string componentType, size_t index);
        std::string getComponentNameFromLine(size_t index);
        void checkComponentName(std::string componentType, size_t index);
        void checkLinksField(void);
        void checkLinksLine(size_t index);
        std::string getNameFromNameValue(std::string NameValue);
        std::string getValueFromNameValue(std::string NameValue);
        void checkLinksName(std::string name, size_t index, bool first);
        void checkLinksValue(std::string name, size_t value, size_t index, bool first);
        std::vector<std::tuple<std::string, size_t>> generateComponentPin(void);
        std::vector<std::tuple<std::string, std::string>> getChipsetVec(void);
        std::vector<std::tuple<std::string, size_t, std::string, size_t>> getLinksVec(void);
    protected:
        std::vector<std::string> _fileContent;
        std::vector<std::tuple<std::string, std::string>> _chipsets;
        std::vector<std::tuple<std::string, size_t, std::string, size_t>> _links;
    private:
};

#endif /* !NANOPARSER_HPP_ */