/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** OSModule
*/

#include "OSModule.hpp"

OSModule::OSModule() : DefaultModule::DefaultModule()
{
    struct utsname buf;

    uname(&buf);
    Data = buf.sysname;
    Displayed = true;
    Type = OSTYPE;
}

OSModule::~OSModule()
{
}

void OSModule::updateData(void)
{
    struct utsname buf;

    uname(&buf);
    Data = buf.sysname;
}
