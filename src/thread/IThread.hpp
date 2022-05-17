/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** IThread
*/

#pragma once

namespace plazza {
    class IThread {
        public:
            virtual ~IThread() = default;

            virtual void join() = 0;
    };
}
