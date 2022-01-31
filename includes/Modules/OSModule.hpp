/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** OSModule
*/

#ifndef OSMODULE_HPP_
#define OSMODULE_HPP_

class DefaultModule;

#include "DefaultModule.hpp"

class OSModule : virtual public DefaultModule {
    public:
        OSModule();
        ~OSModule();
        void updateData();
    protected:
    private:
};

#endif /* !OSMODULE_HPP_ */
