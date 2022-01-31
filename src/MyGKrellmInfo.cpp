/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** MyGKrellmInfo
*/

#include "MyGKrellmInfo.hpp"

ModuleList_t *createNode(IMonitorModule *newModule)
{
    ModuleList_t *node = new ModuleList_t;

    node->module = newModule;
    node->next = nullptr;
    return (node);
}

MyGKrellmInfo::MyGKrellmInfo()
{
    ModuleList_t *list = createNode(new HostUserNameModule);
    list->next = createNode(new OSModule);
    list->next->next = createNode(new KernelVersionModule);
    list->next->next->next = createNode(new DateTimeModule);
    modules = list;
}

MyGKrellmInfo::~MyGKrellmInfo()
{
    ModuleList_t *temp = modules;

    for ( ; temp->next != NULL; delete modules) {
        delete temp->module;
        modules = temp;
        temp = temp->next;
    }
    delete temp->module;
    delete temp;
}

ModuleList_t *MyGKrellmInfo::getModules(void)
{
    return (modules);
}

IMonitorModule *MyGKrellmInfo::getHostUsername(void)
{
    ModuleList_t *temp = modules;

    for ( ; temp->module->getType() != HOSTUSERNAME; temp = temp->next);
    return (temp->module);
}

IMonitorModule *MyGKrellmInfo::getOS(void)
{
    ModuleList_t *temp = modules;

    for ( ; temp->module->getType() != OSTYPE; temp = temp->next);
    return (temp->module);
}

IMonitorModule *MyGKrellmInfo::getKernelVersion(void)
{
    ModuleList_t *temp = modules;

    for ( ; temp->module->getType() != KERNELVERSION; temp = temp->next);
    return (temp->module);
}

IMonitorModule *MyGKrellmInfo::getDateTime(void)
{
    ModuleList_t *temp = modules;

    for ( ; temp->module->getType() != DATETIME; temp = temp->next);
    return (temp->module);
}

/*void MyGKrellmInfo::printInfo(void)
{
    std::cout << "Hostname : " << hostname->getData() << std::endl;
    std::cout << "Username : " << username->getData() << std::endl;
    std::cout << "OS : " << OS->getData() << std::endl;
    std::cout << "Kernel Version : " << kernelVersion->getData() << std::endl;
    std::cout << "Date and Time : " << dateTime->getData() << std::endl;
}*/
