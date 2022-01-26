#pragma once

#include <string>

class NasaError : public std::exception
{
    private:
        std::string _message;
    protected:
        std::string _component;
    public:
        NasaError(std::string const &message, std::string const &component = "Unknown");
        const char *what() const noexcept override;
        std::string const &getComponent() const;
};

class MissionCriticalError : public NasaError
{
    public:
        MissionCriticalError(std::string const &message, std::string const &component = "Unknown");
};

class LifeCriticalError : public NasaError
{
    public:
        LifeCriticalError(std::string const &message, std::string const &component = "Unknown");
};

class UserError : public NasaError
{
    public:
        UserError(std::string const &message, std::string const &component = "Unknown");
};

class CommunicationError : public NasaError
{
    public:
        CommunicationError(std::string const &message);
};
