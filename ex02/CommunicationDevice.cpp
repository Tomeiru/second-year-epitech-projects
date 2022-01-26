#include <iostream>
#include <stdexcept>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(std::istream &input, std::ostream &output) try : _api(input, output) {}
    catch (std::exception const &error) {
        std::string err_str = "Error: ";
        err_str.append(error.what());
        throw CommunicationError(err_str);
    }

CommunicationDevice::~CommunicationDevice()
{
}

void    CommunicationDevice::startMission(std::string const &missionName, std::string *users, size_t nbUsers)
{
    for (size_t i = 0; i < nbUsers; ++i) {
        try {
            _api.addUser(users[i]);
        }
        catch (std::logic_error const &error) {
            std::string err_str = "LogicError: ";
            err_str.append(error.what());
            throw CommunicationError(err_str);
        }
        catch (std::runtime_error const &error) {
            std::string err_str = "RuntimeError: ";
            err_str.append(error.what());
            throw CommunicationError(err_str);
        }
        catch (std::exception const &error) {
            std::string err_str = "Error: ";
            err_str.append(error.what());
            throw CommunicationError(err_str);
        }
    }
    try {
        _api.startMission(missionName);
    }
    catch (std::logic_error const &error) {
        std::string err_str = "LogicError: ";
        err_str.append(error.what());
        throw CommunicationError(err_str);
    }
    catch (std::runtime_error const &error) {
        std::string err_str = "RuntimeError: ";
        err_str.append(error.what());
        throw CommunicationError(err_str);
    }
    catch (std::exception const &error) {
        std::string err_str = "Error: ";
        err_str.append(error.what());
        throw CommunicationError(err_str);
    }
}

void    CommunicationDevice::send(std::string const &user, std::string const &message) const
{
    try {
        _api.sendMessage(user, message);
    }
    catch (std::exception const &error) {
        std::cerr << error.what() << std::endl;
    }
}

void    CommunicationDevice::receive(std::string const &user, std::string &message) const
{
    try {
        _api.receiveMessage(user, message);
    }
    catch (std::exception const &error) {
        std::cerr << error.what() << std::endl;
        std::cerr << "INVALID MESSAGE";
    }
}
