/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** UsernameModule
*/

#ifndef USERNAMEMODULE_HPP_
#define USERNAMEMODULE_HPP_

class DefaultModule;

#include "DefaultModule.hpp"

class UsernameModule : virtual public DefaultModule  {
    public:
        UsernameModule();
        ~UsernameModule();
        void updateData();
    protected:
    private:
};

#endif /* !USERNAMEMODULE_HPP_ */
