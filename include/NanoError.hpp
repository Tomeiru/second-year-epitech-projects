/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** NanoError
*/

#ifndef NANOERROR_HPP_
#define NANOERROR_HPP_

#include "NanoTekSpice.hpp"

class NanoError : public std::exception {
    public:
        NanoError(std::string const &message);
        const char *what() const noexcept override;
        ~NanoError();

    protected:
        std::string _message;
    private:
};

#endif /* !NANOERROR_HPP_ */
