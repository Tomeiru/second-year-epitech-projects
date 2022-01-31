/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** KernelVersionModule
*/

#include "KernelVersionModule.hpp"

KernelVersionModule::KernelVersionModule() : DefaultModule::DefaultModule()
{
    struct utsname buf;

    uname(&buf);
    Data = buf.release;
    Displayed = true;
    Type = KERNELVERSION;
}

KernelVersionModule::~KernelVersionModule()
{
}

void KernelVersionModule::updateData(void)
{
    struct utsname buf;

    uname(&buf);
    Data = buf.release;
}

