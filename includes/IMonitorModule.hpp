/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

#include <iostream>

enum ModuleType {
    DEFAULT,
    HOSTUSERNAME,
    OSKERNELVERSION,
    DATETIME
};

class IMonitorModule {
    public:
        virtual ~IMonitorModule() {};
        virtual std::string getData() = 0;
        virtual bool getDisplayed() = 0;
        virtual ModuleType getType() = 0;
        virtual void toggleDisplayed() = 0;
        virtual void updateData() = 0;
    protected:
    private:
};

#endif /* !IMONITORMODULE_HPP_ */
