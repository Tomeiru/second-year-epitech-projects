/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** startNcurses
*/

#include <signal.h>
#include "MyGKrellmInfo.hpp"

void inputGestion(MyGKrellmInfo *info)
{
    int ch = getch();

    switch (ch) {
        case 'q' :
            endwin();
            exit(0);
            break;
        case 'h' :
            info->getHelpModule()->toggleDisplayed();
            break;
        case 'u' :
            info->getHostUsername()->toggleDisplayed();
            break;
        case 'o' :
            info->getOSKernelVersion()->toggleDisplayed();
            break;
        case 'd' :
            info->getDateTime()->toggleDisplayed();
            break;
    }
}

void resizeHandler(int dummy)
{
    clear();
}

int startCurses(MyGKrellmInfo *info)
{
    int windowWidth = 0;
    int windowHeight = 0;
    int a = -1;

    initscr();
    noecho();
    curs_set(0);

    while (1) {
        getmaxyx(stdscr, windowHeight, windowWidth);
        for (ModuleList_t *temp = info->getModules(); temp != nullptr; temp = temp->next)
            if (info->getHelpModule()->getDisplayed() == true)
                mvprintw(0, 0, "%s", info->getHelpModule()->getData().c_str());
            else if (temp->module->getDisplayed() == true)
                mvprintw(windowHeight / 2 - a++, windowWidth / 2 - temp->module->getData().length() / 2, "%s", temp->module->getData().c_str());
        info->getDateTime()->updateData();
        a = -1;
        timeout(0);
        inputGestion(info);
        signal(SIGWINCH, resizeHandler);
        refresh();
    }
    endwin();
    std::cout << windowHeight << " " << windowWidth << std::endl;
    return (0);
}