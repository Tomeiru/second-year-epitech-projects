/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** OSModule
*/

#include "OSModule.hpp"

OSModule::OSModule()
{
    struct utsname buf;

    uname(&buf);
    OS = buf.sysname;
}

OSModule::~OSModule()
{
}

std::string OSModule::getData(void)
{
    return (OS);
}

void OSModule::updateData(void)
{
    struct utsname buf;

    uname(&buf);
    OS = buf.sysname;
}
