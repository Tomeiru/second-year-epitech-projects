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
            ~IMutex() = default;

            virtual void lock() = 0;
            virtual void unlock() = 0;

        protected:
        private:
    };
}
