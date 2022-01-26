/*
** EPITECH PROJECT, 2022
** Day10PM
** File description:
** Errors
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component = "Unknown") : _message(message), _component(component)
{
}

std::string const &NasaError::getComponent() const
{
    return (_component);
}

const char *NasaError::what() const noexcept
{
    return (_message.data());
}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component = "Unknown") : NasaError::NasaError(message, component)
{

}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component = "Unknown") : NasaError::NasaError(message, component)
{

}

UserError::UserError(std::string const &message, std::string const &component = "Unknown") : NasaError::NasaError(message, component)
{

}

CommunicationError::CommunicationError(std::string const &message) : NasaError::NasaError(message, "CommunicationDevice")
{
}

