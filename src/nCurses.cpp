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
    int windowWidth = 0;
    int windowHeight = 0;
    int i = 0;

    initscr();
    getmaxyx(stdscr, windowHeight, windowWidth);
    curs_set(0);

    while (1) {
        for (ModuleList_t *temp = info->getModules(); temp != nullptr; temp = temp->next)
            if (temp->module->getDisplayed() == true)
                mvprintw(i++, 0, "%s", temp->module->getData().c_str());
        info->getDateTime()->updateData();
        i = 0;
        refresh();
    }
    /*while (1) {
        mvprintw(windowHeight / 2 - 2, windowWidth / 2 - info->getHostname()->getData().length() / 2, "%s\n", info->getHostname()->getData().c_str());
        mvprintw(windowHeight / 2 - 1, windowWidth / 2 - info->getUsername()->getData().length() / 2, "%s\n", info->getUsername()->getData().c_str());
        mvprintw(windowHeight / 2, windowWidth / 2 - info->getOS()->getData().length() / 2 - info->getKernelVersion()->getData().length() / 2, "%s %s\n", info->getOS()->getData().c_str(), info->getKernelVersion()->getData().c_str());
        mvprintw(windowHeight / 2 + 1, windowWidth / 2 - info->getDateTime()->getData().length() / 2, "%s\n", info->getDateTime()->getData().c_str());
        info->getDateTime()->updateData();
    }*/
    endwin();
    std::cout << windowHeight << " " << windowWidth << std::endl;
    return (0);
}