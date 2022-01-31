/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** MyGKrellmInfo
*/

#include "MyGKrellm.hpp"

MyGKrellmInfo::MyGKrellmInfo(char **env)
{
    struct utsname buf;
    time_t now = time(0);
    struct tm tstruct;
    char buff[22];

    uname(&buf);
    tstruct = *localtime(&now);
    strftime(buff, sizeof(buff), "%d/%m/%Y : %X", &tstruct);
    hostname = buf.nodename;
    for (int i = 0; env[i]; i++)
        if (strstr(env[i], "USERNAME=") != nullptr)
            username = env[i] + 9;
    OS = buf.sysname;
    kernelVersion = buf.release;
    dateTime = buff;
}

MyGKrellmInfo::~MyGKrellmInfo()
{
}

std::string MyGKrellmInfo::getHostname(void)
{
    return (hostname);
}

std::string MyGKrellmInfo::getUsername(void)
{
    return (username);
}

std::string MyGKrellmInfo::getOS(void)
{
    return (OS);
}

std::string MyGKrellmInfo::getKernelVersion(void)
{
    return (kernelVersion);
}

std::string MyGKrellmInfo::getDateTime(void)
{
    return (dateTime);
}

void MyGKrellmInfo::refreshDateTime(void)
{
    time_t now = time(0);
    struct tm tstruct;
    char buff[22];

    tstruct = *localtime(&now);
    strftime(buff, sizeof(buff), "%d/%m/%Y : %X", &tstruct);
    dateTime = buff;
}

void MyGKrellmInfo::printInfo(void)
{
    std::cout << "Hostname : " << hostname << std::endl;
    std::cout << "Username : " << username << std::endl;
    std::cout << "OS : " << OS << std::endl;
    std::cout << "Kernel Version : " << kernelVersion << std::endl;
    std::cout << "Date and Time : " << dateTime << std::endl;
}
