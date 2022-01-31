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
}

HostnameModule::~HostnameModule()
{
}

std::string HostnameModule::getData(void)
{
    return (hostname);
}

void HostnameModule::updateData(void)
{
    struct utsname buf;

    uname(&buf);
    hostname = buf.nodename;
}
