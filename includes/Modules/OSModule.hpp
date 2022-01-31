/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** OSModule
*/

#ifndef OSMODULE_HPP_
#define OSMODULE_HPP_

#include "IMonitorModule.hpp"
#include "MyGKrellm.hpp"

class OSModule : public IMonitorModule {
    public:
        OSModule();
        ~OSModule();
        std::string getData();
        bool getDisplayed();
        ModuleType getType();
        void toggleDisplayed();
        void updateData();
    protected:
        std::string OS;
        bool Displayed;
        ModuleType Type;
    private:
};

#endif /* !OSMODULE_HPP_ */
