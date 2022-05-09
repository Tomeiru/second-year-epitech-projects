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
#include "NamedPipes.hpp"

plazza::NamedPipes::NamedPipes()
{
    static int id = 0;

    _id = id++;
    _ptcPath << "/tmp/kitchen" << id << "_ptc";
    _ctpPath << "/tmp/kitchen" << id << "_ctp";
    if (mkfifo(_ptcPath.str().c_str(), 0666) == -1 && errno != EEXIST)
        throw std::runtime_error("Could not create FIFO files");
    if (mkfifo(_ctpPath.str().c_str(), 0666) == -1 && errno != EEXIST)
        throw std::runtime_error("Could not create FIFO files");
}

plazza::NamedPipes::~NamedPipes()
{
    if (_readFd != -1)
        close(_readFd);
    if (_writeFd != -1)
        close(_writeFd);
}

void plazza::NamedPipes::send(void *data, std::size_t size)
{
    if (_side == ProcessType::UNDEFINED)
        throw ProcessComSideUndef();
    write(_writeFd, data, size);
}

int plazza::NamedPipes::recv(void *buf, std::size_t size)
{
    if (_side == ProcessType::UNDEFINED)
        throw ProcessComSideUndef();
    return read(_readFd, buf, size);
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
        _readFd = open(_ctpPath.str().c_str(), O_RDONLY);
        _writeFd = open(_ptcPath.str().c_str(), O_WRONLY);
    } else if (_side == ProcessType::CHILD) {
        _writeFd = open(_ctpPath.str().c_str(), O_WRONLY);
        _readFd = open(_ptcPath.str().c_str(), O_RDONLY);
    }
}
