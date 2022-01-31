/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** UsernameModule
*/

#include "UsernameModule.hpp"

UsernameModule::UsernameModule()
{
    username = getlogin();
    Displayed = true;
    Type = USERNAME;
}

UsernameModule::~UsernameModule()
{
}

std::string UsernameModule::getData(void)
{
    return (username);
}

bool UsernameModule::getDisplayed(void)
{
    return (Displayed);
}

ModuleType UsernameModule::getType(void)
{
    return (Type);
}

void UsernameModule::toggleDisplayed()
{
    Displayed = (Displayed == true) ? false : true;
}

void UsernameModule::updateData()
{
    username = getlogin();
}
