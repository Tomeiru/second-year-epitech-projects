/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** MyGKrellmInfo
*/

#include "MyGKrellm.hpp"

MyGKrellmInfo::MyGKrellmInfo()
{
    hostname = new HostnameModule;
    username = new UsernameModule();
    OS = new OSModule;
    kernelVersion = new KernelVersionModule;
    dateTime = new DateTimeModule;
}

MyGKrellmInfo::~MyGKrellmInfo()
{
    delete hostname;
    delete username;
    delete OS;
    delete kernelVersion;
    delete dateTime;
}

IMonitorModule *MyGKrellmInfo::getHostname(void)
{
    return (hostname);
}

IMonitorModule *MyGKrellmInfo::getUsername(void)
{
    return (username);
}

IMonitorModule *MyGKrellmInfo::getOS(void)
{
    return (OS);
}

IMonitorModule *MyGKrellmInfo::getKernelVersion(void)
{
    return (kernelVersion);
}

IMonitorModule *MyGKrellmInfo::getDateTime(void)
{
    return (dateTime);
}

void MyGKrellmInfo::printInfo(void)
{
    std::cout << "Hostname : " << hostname->getData() << std::endl;
    std::cout << "Username : " << username->getData() << std::endl;
    std::cout << "OS : " << OS->getData() << std::endl;
    std::cout << "Kernel Version : " << kernelVersion->getData() << std::endl;
    std::cout << "Date and Time : " << dateTime->getData() << std::endl;
}
