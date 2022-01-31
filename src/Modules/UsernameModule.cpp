/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** UsernameModule
*/

#include "UsernameModule.hpp"

UsernameModule::UsernameModule(char **env)
{
    for (int i = 0; env[i]; i++)
        if (strstr(env[i], "USERNAME=") != nullptr)
            username = env[i] + 9;
    envBU = env;
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
    for (int i = 0; envBU[i]; i++)
        if (strstr(envBU[i], "USERNAME=") != nullptr)
            username = envBU[i] + 9;
}
