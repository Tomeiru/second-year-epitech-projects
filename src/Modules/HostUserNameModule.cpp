/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** HostUserNameModule
*/

#include "HostUserNameModule.hpp"

HostUserNameModule::HostUserNameModule()
{
    struct utsname buf;

    uname(&buf);
    Data = getlogin();
    Data.append(" ");
    Data.append(buf.nodename);
    Type = HOSTUSERNAME;
}

HostUserNameModule::~HostUserNameModule()
{
}

void HostUserNameModule::updateData(void)
{
    struct utsname buf;

    uname(&buf);
    Data = getlogin();
    Data.append(" ");
    Data.append(buf.nodename);
}