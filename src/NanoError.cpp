/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** NanoError
*/

#include "NanoError.hpp"

NanoError::NanoError(std::string const &message)
{
    _message = message;
}

NanoError::~NanoError()
{
}

const char *NanoError::what() const noexcept
{
    return (_message.data());
}
