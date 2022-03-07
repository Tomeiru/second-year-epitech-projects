/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** UnsoldError
*/

#include "Error.hpp"

UnsoldError::UnsoldError(std::string const &message)
{
    _message = message;
}

UnsoldError::~UnsoldError()
{
}

const char *UnsoldError::what() const noexcept
{
    return (_message.data());
}
