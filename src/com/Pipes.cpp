/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** Pipes
*/

#include <unistd.h>
#include <stdexcept>
#include "Pipes.hpp"

plazza::Pipes::Pipes()
{
    if (pipe(_parentToChild) == -1 || pipe(_childToParent) == -1)
        throw std::runtime_error("Could not init pipes");
}

plazza::Pipes::~Pipes()
{
    close(_parentToChild[0]);
    close(_parentToChild[1]);
    close(_childToParent[0]);
    close(_childToParent[1]);
}

void plazza::Pipes::send(void *data, std::size_t size)
{
    if (_side == ProcessType::PARENT)
        write(_parentToChild[0], data, size);
    else if (_side == ProcessType::CHILD)
        write(_childToParent[0], data, size);
    else
        throw ProcessComSideUndef();
}

int plazza::Pipes::recv(void *buf, std::size_t size)
{
    if (_side == ProcessType::PARENT)
        return read(_childToParent[1], buf, size);
    else if (_side == ProcessType::CHILD)
        return read(_parentToChild[1], buf, size);
    else
        throw ProcessComSideUndef();
}

void plazza::Pipes::setComSide(ProcessType type)
{
    if (_side != ProcessType::UNDEFINED)
        throw ProcessComSideAlreadySet();
    if (type == ProcessType::PARENT) {
        _side = ProcessType::PARENT;
        close(_parentToChild[1]);
        close(_childToParent[0]);
        _parentToChild[1] = -1;
        _childToParent[0] = -1;
    } else if (type == ProcessType::CHILD) {
        _side = ProcessType::CHILD;
        close(_parentToChild[0]);
        close(_childToParent[1]);
        _parentToChild[0] = -1;
        _childToParent[1] = -1;
    }
}
