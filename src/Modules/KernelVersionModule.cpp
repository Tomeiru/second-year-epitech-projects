/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** KernelVersionModule
*/

#include "KernelVersionModule.hpp"

KernelVersionModule::KernelVersionModule()
{
    struct utsname buf;

    uname(&buf);
    KernelVersion = buf.release;
}

KernelVersionModule::~KernelVersionModule()
{
}

std::string KernelVersionModule::getData(void)
{
    return (KernelVersion);
}

void KernelVersionModule::updateData(void)
{
    struct utsname buf;

    uname(&buf);
    KernelVersion = buf.release;
}

