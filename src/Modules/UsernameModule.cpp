/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** UsernameModule
*/

#include "UsernameModule.hpp"

UsernameModule::UsernameModule() : DefaultModule::DefaultModule()
{
    Data = getlogin();
    Displayed = true;
    Type = USERNAME;
}

UsernameModule::~UsernameModule()
{
}

void UsernameModule::updateData()
{
    Data = getlogin();
}
