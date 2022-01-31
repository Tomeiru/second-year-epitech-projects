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
        void updateData();
    protected:
        std::string KernelVersion;
    private:
};

#endif /* !KERNELVERSIONMODULE_HPP_ */
