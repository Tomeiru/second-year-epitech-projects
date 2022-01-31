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
}

UsernameModule::~UsernameModule()
{
}

std::string UsernameModule::getData(void)
{
    return (username);
}

void UsernameModule::updateData()
{
    username = getlogin();
}
