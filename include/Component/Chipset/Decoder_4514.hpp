/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Decoder_4514
*/

#ifndef DECODER_4514_HPP_
#define DECODER_4514_HPP_

#include "Component.hpp"

class Decoder_4514 : public Component{
    public:
        Decoder_4514(std::string name);
        ~Decoder_4514();
        void simulate(std::size_t tick);
    protected:
    private:
};

#endif /* !DECODER_4514_HPP_ */
