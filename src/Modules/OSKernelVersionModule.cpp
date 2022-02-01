/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** OSKernelVersionModule
*/

#include "OSKernelVersionModule.hpp"

OSKernelVersionModule::OSKernelVersionModule()
{
    struct utsname buf;

    uname(&buf);
    Title = "OS and Kernel Version:";
    Data = buf.sysname;
    Data.append(" ");
    Data.append(buf.release);
    Type = OSKERNELVERSION;
}

OSKernelVersionModule::~OSKernelVersionModule()
{
}

void OSKernelVersionModule::updateData(void)
{
    struct utsname buf;

    uname(&buf);
    Data = buf.sysname;
    Data.append(" ");
    Data.append(buf.release);
}