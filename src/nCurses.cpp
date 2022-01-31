/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** startNcurses
*/

#include "MyGKrellm.hpp"
#include "MyGKrellmInfo.hpp"

int startCurses(MyGKrellmInfo *info)
{
    initscr();
    curs_set(0);
    while (1) {
        mvprintw(0, 0, "%s\n", info->getHostname()->getData().c_str());
        mvprintw(1, 0, "%s\n", info->getUsername()->getData().c_str());
        mvprintw(2, 0, "%s %s\n", info->getOS()->getData().c_str(), info->getKernelVersion()->getData().c_str());
        mvprintw(3, 0, "%s\n", info->getDateTime()->getData().c_str());
        info->getDateTime()->updateData();
        refresh();
    }
    endwin();
    return (0);
}