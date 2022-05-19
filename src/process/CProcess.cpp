/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** CProcess
*/

#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdexcept>
#include "CProcess.hpp"

plazza::CProcess::CProcess(ProcessStartFct fct, void *args) : _com{}
{
    _pid = fork();

    if (_pid == -1)
        throw std::runtime_error("Could not fork program");
    if (_pid == 0) {
        _com.setComSide(CHILD);
        fct(_com, args);
        exit(0);
    } else
        _com.setComSide(PARENT);
}

plazza::CProcess::~CProcess()
{
}

void plazza::CProcess::close()
{
    int ret;

    waitpid(_pid, &ret, 0);
}

plazza::IProcessCom &plazza::CProcess::getCom()
{
    return _com;
}
