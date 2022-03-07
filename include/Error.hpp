/*
** EPITECH PROJECT, 2022
** Unsold
** File description:
** UnsoldError
*/

#ifndef UNSOLDERROR_HPP_
#define UNSOLDERROR_HPP_

#include "Unsold.hpp"

class UnsoldError : public std::exception {
    public:
        UnsoldError(std::string const &message);
        const char *what() const noexcept override;
        ~UnsoldError();

    protected:
        std::string _message;
    private:
};

#endif /* !UNSOLDERROR_HPP_ */
