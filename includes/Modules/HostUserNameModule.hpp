/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** HostUserNameModule
*/

#ifndef HOSTUSERNAMEMODULE_HPP_
#define HOSTUSERNAMEMODULE_HPP_

class DefaultModule;

#include "DefaultModule.hpp"

class HostUserNameModule : virtual public DefaultModule {
    public:
        HostUserNameModule();
        ~HostUserNameModule();
        void updateData();
    protected:
    private:
};

#endif /* !HOSTUSERNAMEMODULE_HPP_ */
