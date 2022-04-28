/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** IProcessCom
*/

#pragma once

class IProcessCom {
    public:
        ~IProcessCom() = default;

        virtual void send() = 0;
        virtual void recv() = 0;

    protected:
    private:
};
