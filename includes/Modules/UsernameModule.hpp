/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** UsernameModule
*/

#ifndef USERNAMEMODULE_HPP_
#define USERNAMEMODULE_HPP_

#include "IMonitorModule.hpp"
#include "MyGKrellm.hpp"

class UsernameModule : public IMonitorModule {
    public:
        UsernameModule();
        ~UsernameModule();
        std::string getData();
        bool getDisplayed();
        ModuleType getType();
        void toggleDisplayed();
        void updateData();
    protected:
        std::string username;
        bool Displayed;
        ModuleType Type;
    private:
};

#endif /* !USERNAMEMODULE_HPP_ */
