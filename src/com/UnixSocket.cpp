/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** UnixSocket
*/

#include <unistd.h>
#include <sys/socket.h>
#include <stdexcept>
#include "UnixSocket.hpp"

plazza::UnixSocket::UnixSocket()
{
    _socket = socket(AF_UNIX, SOCK_STREAM, 0);

    if (_socket == -1)
        throw std::runtime_error("Could not open socket");
}

plazza::UnixSocket::~UnixSocket()
{
    close(_socket);
}
