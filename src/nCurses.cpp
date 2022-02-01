/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** startNcurses
*/

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

int startCurses(MyGKrellmInfo *info)
{
    int windowWidth = 0;
    int windowHeight = 0;
    int a = -1;

    initscr();
    getmaxyx(stdscr, windowHeight, windowWidth);
    noecho();
    curs_set(0);

    while (1) {
        for (ModuleList_t *temp = info->getModules(); temp != nullptr; temp = temp->next)
            if (info->getHelpModule()->getDisplayed() != true && temp->module->getDisplayed() == true)
                mvprintw(windowHeight / 2 - a++, windowWidth / 2 - temp->module->getData().length() / 2, "%s", temp->module->getData().c_str());
        info->getDateTime()->updateData();
        a = -1;
        timeout(0);
        inputGestion(info);
        refresh();
    }
    endwin();
    std::cout << windowHeight << " " << windowWidth << std::endl;
    return (0);
}