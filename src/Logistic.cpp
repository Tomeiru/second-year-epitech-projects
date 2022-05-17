/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Logistic
*/

#include "Logistic.hpp"

Logistic::Logistic()
{
    _status = false;
    _end = false;
}

Logistic::~Logistic()
{
}

void Logistic::pushBackQueue(std::unique_ptr<plazza::Order> order)
{
    _queue.push_back(std::move(order));
}

unsigned int Logistic::getQueueSize() const
{
    if (_queue.empty())
        return (0);
    return (_queue.size());
}

void Logistic::toggleStatus()
{
    _status = (_status ? false : true);
}

void Logistic::toggleEnd()
{
    _end = (_status ? false : true);
}

bool Logistic::getStatus() const
{
    return (_status);
}

bool Logistic::getEnd() const
{
    return (_end);
}

void Logistic::lockMutex()
{
    _mutex.lock();
}

void Logistic::unlockMutex()
{
    _mutex.unlock();
}
