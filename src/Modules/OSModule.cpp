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
    Displayed = true;
    Type = OSTYPE;
}

OSModule::~OSModule()
{
}

std::string OSModule::getData(void)
{
    return (OS);
}

bool OSModule::getDisplayed(void)
{
    return (Displayed);
}

ModuleType OSModule::getType(void)
{
    return (Type);
}

void OSModule::toggleDisplayed()
{
    Displayed = (Displayed == true) ? false : true;
}

void OSModule::updateData(void)
{
    struct utsname buf;

    uname(&buf);
    OS = buf.sysname;
}
