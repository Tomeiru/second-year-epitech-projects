/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** DateTimeModule
*/

#ifndef DATETIMEMODULE_HPP_
#define DATETIMEMODULE_HPP_

class DefaultModule;

#include "DefaultModule.hpp"

class DateTimeModule : virtual public DefaultModule {
    public:
        DateTimeModule();
        ~DateTimeModule();
        void updateData();
    protected:
    private:
};

#endif /* !DATETIMEMODULE_HPP_ */
