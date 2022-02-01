/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** HelpModule
*/

#include "HelpModule.hpp"

HelpModule::HelpModule() : DefaultModule::DefaultModule()
{
    Data = "Hotkeys\n\nH - Toggle the Help screen\nQ - Quit the application\n\nU - Show/Hide the Username and Hostname\nO - Show/Hide the OS and Kernel Version\nD - Show/Hide the Date and Time\nS - Switch from nCurses to SFML and vice versa\n";
    Displayed = false;
    Type = HELP;
}

HelpModule::~HelpModule()
{
}
