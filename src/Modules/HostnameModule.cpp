/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** HostnameModule
*/

#include "HostnameModule.hpp"

HostnameModule::HostnameModule() : DefaultModule::DefaultModule()
{
    struct utsname buf;

    uname(&buf);
    Data = buf.nodename;
    Displayed = true;
    Type = HOSTNAME;
}

HostnameModule::~HostnameModule()
{
}

void HostnameModule::updateData(void)
{
    struct utsname buf;

    uname(&buf);
    Data = buf.nodename;
}
