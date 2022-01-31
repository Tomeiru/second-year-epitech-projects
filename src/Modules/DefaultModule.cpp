/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** DefaultModule
*/

#include "DefaultModule.hpp"

DefaultModule::DefaultModule()
{
    Displayed = true;
    Type = DEFAULT;
}

DefaultModule::~DefaultModule()
{
}

std::string DefaultModule::getData(void)
{
    return (Data);
}

bool DefaultModule::getDisplayed(void)
{
    return (Displayed);
}

ModuleType DefaultModule::getType(void)
{
    return (Type);
}

void DefaultModule::toggleDisplayed()
{
    Displayed = (Displayed == true) ? false : true;
}

void DefaultModule::updateData()
{
    Data = nullptr;
}