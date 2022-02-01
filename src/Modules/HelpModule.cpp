/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** HelpModule
*/

#include "HelpModule.hpp"

HelpModule::HelpModule() : DefaultModule::DefaultModule()
{
    Data = "";
    Displayed = false;
    Type = HELP;
}

HelpModule::~HelpModule()
{
}
