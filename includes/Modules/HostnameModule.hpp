/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** HostnameModule
*/

#ifndef HOSTNAMEMODULE_HPP_
#define HOSTNAMEMODULE_HPP_

class DefaultModule;

#include "DefaultModule.hpp"

class HostnameModule : virtual public DefaultModule {
    public:
        HostnameModule();
        ~HostnameModule();
        void updateData();
    protected:
    private:
};

#endif /* !HOSTNAMEMODULE_HPP_ */
