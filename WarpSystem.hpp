/*
** EPITECH PROJECT, 2022
** AM
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

#pragma once

#include <iostream>
#include "Destination.hpp"

namespace WarpSystem
{
    class QuantumReactor {
        public:
            QuantumReactor();
            ~QuantumReactor();
            bool isStable();
            void setStability(bool);
        private:
            bool _stability;
    };

    class Core {
        public:
            Core(QuantumReactor *);
            ~Core();
            QuantumReactor *checkReactor();
        private:
            QuantumReactor *_coreReactor;
    };
}

#endif /* !WARPSYSTEM_HPP_ */
