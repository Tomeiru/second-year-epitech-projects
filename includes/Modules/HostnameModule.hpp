/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** HostnameModule
*/

#ifndef HOSTNAMEMODULE_HPP_
#define HOSTNAMEMODULE_HPP_

#include "IMonitorModule.hpp"
#include "MyGKrellm.hpp"

class HostnameModule : public IMonitorModule {
    public:
        HostnameModule();
        ~HostnameModule();
        std::string getData();
        bool getDisplayed();
        ModuleType getType();
        void toggleDisplayed();
        void updateData();
    protected:
        std::string hostname;
        bool Displayed;
        ModuleType Type;
    private:
};

#endif /* !HOSTNAMEMODULE_HPP_ */
