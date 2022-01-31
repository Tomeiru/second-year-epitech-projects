/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** DateTimeModule
*/

#ifndef DATETIMEMODULE_HPP_
#define DATETIMEMODULE_HPP_

#include "IMonitorModule.hpp"
#include "MyGKrellm.hpp"

class DateTimeModule : public IMonitorModule {
    public:
        DateTimeModule();
        ~DateTimeModule();
        std::string getData();
        void updateData();
    protected:
        std::string DateTime;
    private:
};

#endif /* !DATETIMEMODULE_HPP_ */
