/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** startNcurses
*/

#include <signal.h>
#include "MyGKrellmInfo.hpp"

int inputGestion(MyGKrellmInfo *info, WINDOW *my_win)
{
    int ch = getch();

    switch (ch) {
        case 'q' :
            endwin();
            exit(0);
            break;
        case 'h' :
            info->getHelpModule()->toggleDisplayed();
            wclear(my_win);
            break;
        case 'u' :
            info->getHostUsername()->toggleDisplayed();
            wclear(my_win);
            break;
        case 'o' :
            info->getOSKernelVersion()->toggleDisplayed();
            wclear(my_win);
            break;
        case 'd' :
            info->getDateTime()->toggleDisplayed();
            wclear(my_win);
            break;
        case 's' :
            return (1);
    }
    return (0);
}

void resizeHandler(int dummy)
{
    (void)(dummy);
    clear();
}

int startCurses(MyGKrellmInfo *info)
{
    initscr();
    int height = LINES;
    int width = 40;
    int winY = 0;
    int winX = (COLS / 2) - 20;
    WINDOW *my_win = newwin(height, width, winY, winX);;
    int a = 2;

    cbreak();
    refresh();
    curs_set(0);
    noecho();
    while (1) {
        for (ModuleList_t *temp = info->getModules(); temp != nullptr; temp = temp->next)
            if (info->getHelpModule()->getDisplayed() == true)
                mvprintw(0, 0, "%s", info->getHelpModule()->getData().c_str());
            else if (temp->module->getDisplayed() == true) {
                box(my_win, 0, 0);
                mvwprintw(my_win, a++, width / 2 - temp->module->getTitle().length() / 2, "%s", temp->module->getTitle().c_str());
                mvwprintw(my_win, a++, width / 2 - temp->module->getData().length() / 2, "%s", temp->module->getData().c_str());
                a += 2;
            }
        info->getDateTime()->updateData();
        timeout(0);
        if (inputGestion(info, my_win) == 1) {
            endwin();
            startSFML(info);
            break;
        }
        signal(SIGWINCH, resizeHandler);
        wrefresh(my_win);
        a = 2;
    }
    endwin();
    return (0);
}