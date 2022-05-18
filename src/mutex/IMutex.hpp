/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** IMutex
*/

#pragma once

namespace plazza {
    class IMutex {
        public:
            virtual ~IMutex() = default;

            virtual void lock() = 0;
            virtual void unlock() = 0;
    };
}
