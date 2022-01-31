/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** KernelVersionModule
*/

#ifndef KERNELVERSIONMODULE_HPP_
#define KERNELVERSIONMODULE_HPP_

class DefaultModule;

#include "DefaultModule.hpp"

class KernelVersionModule : virtual public DefaultModule  {
    public:
        KernelVersionModule();
        ~KernelVersionModule();
        void updateData();
    protected:
    private:
};

#endif /* !KERNELVERSIONMODULE_HPP_ */
