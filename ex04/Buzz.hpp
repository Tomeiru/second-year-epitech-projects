/*
** EPITECH PROJECT, 2022
** Day11
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy {
    public:
        Buzz(const std::string &, const std::string &);
        Buzz(const std::string &);
        ~Buzz();
        void speak(const std::string &);
    protected:
    private:
};

#endif /* !BUZZ_HPP_ */
