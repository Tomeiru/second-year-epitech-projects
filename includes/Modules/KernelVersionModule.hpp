/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** KernelVersionModule
*/

#ifndef KERNELVERSIONMODULE_HPP_
#define KERNELVERSIONMODULE_HPP_

#include "IMonitorModule.hpp"
#include "MyGKrellm.hpp"

class KernelVersionModule : public IMonitorModule {
    public:
        KernelVersionModule();
        ~KernelVersionModule();
        std::string getData();
        bool getDisplayed();
        ModuleType getType();
        void toggleDisplayed();
        void updateData();
    protected:
        std::string KernelVersion;
        bool Displayed;
        ModuleType Type;
    private:
};

#endif /* !KERNELVERSIONMODULE_HPP_ */
