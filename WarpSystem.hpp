/*
** EPITECH PROJECT, 2022
** AM
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

#include <iostream>

namespace WarpSystem
{
    class QuantumReactor {
        public:
            QuantumReactor();
            ~QuantumReactor();
            bool isStable();
            void setStability(bool);
            bool _stability;
    };

    class Core {
        public:
            Core(QuantumReactor *);
            ~Core();
            QuantumReactor *checkReactor();
            QuantumReactor *_coreReactor;
    };
}

#endif /* !WARPSYSTEM_HPP_ */
