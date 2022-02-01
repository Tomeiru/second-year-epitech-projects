/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** MyGKrellmInfo
*/

#ifndef MYGKRELLMINFO_HPP_
#define MYGKRELLMINFO_HPP_

#include "DateTimeModule.hpp"
#include "HostUserNameModule.hpp"
#include "OSKernelVersionModule.hpp"
#include "HelpModule.hpp"

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
        IMonitorModule *getHelpModule();
    protected:
        ModuleList_t *modules;
        IMonitorModule *helpModule;
    private:
};

void argumentCheck(int ac, char **av);
int startCurses(MyGKrellmInfo *info);
void startSFML(MyGKrellmInfo *info);

#endif /* !MYGKRELLMINFO_HPP_ */
