/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** DateTimeModule
*/

#include "DateTimeModule.hpp"

DateTimeModule::DateTimeModule()
{
    time_t now = time(0);
    struct tm tstruct;
    tstruct = *localtime(&now);
    char buff[22];

    strftime(buff, sizeof(buff), "%d/%m/%Y : %X", &tstruct);
    DateTime = buff;
}

DateTimeModule::~DateTimeModule()
{
}

std::string DateTimeModule::getData(void)
{
    return (DateTime);
}

void DateTimeModule::updateData(void)
{
    time_t now = time(0);
    struct tm tstruct;
    tstruct = *localtime(&now);
    char buff[22];

    strftime(buff, sizeof(buff), "%d/%m/%Y : %X", &tstruct);
    DateTime = buff;
}
