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
    Displayed = true;
    Type = KERNELVERSION;
}

KernelVersionModule::~KernelVersionModule()
{
}

std::string KernelVersionModule::getData(void)
{
    return (KernelVersion);
}

bool KernelVersionModule::getDisplayed(void)
{
    return (Displayed);
}

ModuleType KernelVersionModule::getType(void)
{
    return (Type);
}

void KernelVersionModule::toggleDisplayed()
{
    Displayed = (Displayed == true) ? false : true;
}

void KernelVersionModule::updateData(void)
{
    struct utsname buf;

    uname(&buf);
    KernelVersion = buf.release;
}

