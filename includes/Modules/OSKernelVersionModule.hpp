/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** OSKernelVersionModule
*/

#ifndef OSKERNELVERSIONMODULE_HPP_
#define OSKERNELVERSIONMODULE_HPP_

class DefaultModule;

#include "DefaultModule.hpp"

class OSKernelVersionModule : virtual public DefaultModule {
    public:
        OSKernelVersionModule();
        ~OSKernelVersionModule();
        void updateData();
    protected:
    private:
};

#endif /* !OSKERNELVERSIONMODULE_HPP_ */
