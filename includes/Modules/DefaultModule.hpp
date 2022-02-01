/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** DefaultModule
*/

#ifndef DEFAULTMODULE_HPP_
#define DEFAULTMODULE_HPP_

class IMonitorModule;

#include <sys/utsname.h>
#include <unistd.h>
#include <ncurses.h>
#include "IMonitorModule.hpp"

class DefaultModule : public IMonitorModule {
    public:
        DefaultModule();
        ~DefaultModule();
        std::string getData();
        bool getDisplayed();
        ModuleType getType();
        void toggleDisplayed();
        void updateData();
    protected:
        std::string Data;
        bool Displayed;
        ModuleType Type;
    private:
};

#endif /* !DEFAULTMODULE_HPP_ */
