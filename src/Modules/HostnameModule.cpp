/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** HostnameModule
*/

#include "HostnameModule.hpp"

HostnameModule::HostnameModule()
{
    struct utsname buf;

    uname(&buf);
    hostname = buf.nodename;
    Displayed = true;
    Type = HOSTNAME;
}

HostnameModule::~HostnameModule()
{
}

std::string HostnameModule::getData(void)
{
    return (hostname);
}

bool HostnameModule::getDisplayed(void)
{
    return (Displayed);
}

ModuleType HostnameModule::getType(void)
{
    return (Type);
}

void HostnameModule::toggleDisplayed()
{
    Displayed = (Displayed == true) ? false : true;
}

void HostnameModule::updateData(void)
{
    struct utsname buf;

    uname(&buf);
    hostname = buf.nodename;
}
