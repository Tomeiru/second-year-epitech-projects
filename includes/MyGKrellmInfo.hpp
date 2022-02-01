/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** MyGKrellmInfo
*/

#ifndef MYGKRELLMINFO_HPP_
#define MYGKRELLMINFO_HPP_

#include <iostream>
#include <exception>
#include <string>
#include <cstring>
#include <stdint.h>
#include <ncurses.h>
#include "DateTimeModule.hpp"
#include "HostUserNameModule.hpp"
#include "OSKernelVersionModule.hpp"

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
        IMonitorModule *getHostUsername();
        IMonitorModule *getOSKernelVersion();
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

void argumentCheck(int ac, char **av);
int startCurses(MyGKrellmInfo *info);

#endif /* !MYGKRELLMINFO_HPP_ */
