/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** NamedPipes
*/

#include <iostream>
#include <stdexcept>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <poll.h>
#include "NamedPipes.hpp"

plazza::NamedPipes::NamedPipes()
{
    static int id = 0;
    std::ostringstream ptcPathBuf;
    std::ostringstream ctpPathBuf;

    _id = id++;
    ptcPathBuf << "/tmp/kitchen" << id << "_ptc";
    ctpPathBuf << "/tmp/kitchen" << id << "_ctp";
    _ptcPath = ptcPathBuf.str();
    _ctpPath = ctpPathBuf.str();

    if (!access(_ptcPath.c_str(), F_OK))
        remove(_ptcPath.c_str());
    if (!access(_ctpPath.c_str(), F_OK))
        remove(_ctpPath.c_str());

    if (mkfifo(_ptcPath.c_str(), 0666) == -1)
        throw std::runtime_error("Could not create FIFO files");
    if (mkfifo(_ctpPath.c_str(), 0666) == -1)
        throw std::runtime_error("Could not create FIFO files");
}

plazza::NamedPipes::~NamedPipes()
{
    closeCom();
    if (_readFd != -1)
        close(_readFd);
    if (_writeFd != -1)
        close(_writeFd);
    remove(_ptcPath.c_str());
    remove(_ctpPath.c_str());
}

void plazza::NamedPipes::send(void *data, std::size_t size)
{
    if (_side == ProcessType::UNDEFINED)
        throw ProcessComSideUndef();
    if (_closed)
        return;
    write(_writeFd, data, size);
}

int plazza::NamedPipes::recv(void *buf, std::size_t size)
{
    int bytes_read;

    if (_side == ProcessType::UNDEFINED)
        throw ProcessComSideUndef();
    bytes_read = read(_readFd, buf, size);
    if (bytes_read == -1 && errno == EAGAIN)
        return 0;
    return bytes_read;
}

bool plazza::NamedPipes::canRead()
{
    struct pollfd data = { .fd = _readFd, .events = POLLIN, .revents = 0};

    return poll(&data, 1, 1) == 1;
}

// NOTE : order of opening is important
// open() will hang until there is both a reader and a writer
void plazza::NamedPipes::setComSide(ProcessType side)
{
    if (_side != ProcessType::UNDEFINED)
        throw ProcessComSideAlreadySet();
    if (side == ProcessType::UNDEFINED)
        throw ProcessComSideUndef();
    _side = side;
    if (_side == ProcessType::PARENT) {
        _readFd = open(_ctpPath.c_str(), O_RDONLY);
        _writeFd = open(_ptcPath.c_str(), O_WRONLY);
    } else if (_side == ProcessType::CHILD) {
        _writeFd = open(_ctpPath.c_str(), O_WRONLY);
        _readFd = open(_ptcPath.c_str(), O_RDONLY);
    }
}
