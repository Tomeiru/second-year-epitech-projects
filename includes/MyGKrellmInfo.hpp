/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** MyGKrellmInfo
*/

#ifndef MYGKRELLMINFO_HPP_
#define MYGKRELLMINFO_HPP_

#include "DateTimeModule.hpp"
#include "HostnameModule.hpp"
#include "KernelVersionModule.hpp"
#include "OSModule.hpp"
#include "UsernameModule.hpp"

typedef struct ModuleList_s {
    IMonitorModule *module;
    struct ModuleList_s *next;
} ModuleList_t;

ModuleList_t *createNode(IMonitorModule *newModule);

class MyGKrellmInfo {
    public:
        MyGKrellmInfo();
        ~MyGKrellmInfo();
        ModuleList_t *getModules();
        IMonitorModule *getHostname();
        IMonitorModule *getUsername();
        IMonitorModule *getOS();
        IMonitorModule *getKernelVersion();
        IMonitorModule *getDateTime();
        /*void printInfo();*/
    protected:
        ModuleList_t *modules;
        /*IMonitorModule *hostname;
        IMonitorModule *username;
        IMonitorModule *OS;
        IMonitorModule *kernelVersion;
        IMonitorModule *dateTime;*/
    private:
};

#endif /* !MYGKRELLMINFO_HPP_ */
