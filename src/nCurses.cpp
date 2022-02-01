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
    box(my_win, 0, 0);
    while (1) {
        for (ModuleList_t *temp = info->getModules(); temp != nullptr; temp = temp->next)
            if (temp->module->getDisplayed() == true) {
                mvwprintw(my_win, a++, width / 2 - temp->module->getTitle().length() / 2, "%s", temp->module->getTitle().c_str());
                mvwprintw(my_win, a++, width / 2 - temp->module->getData().length() / 2, "%s", temp->module->getData().c_str());
                a += 2;
            }
        info->getDateTime()->updateData();
        wrefresh(my_win);
        a = 2;
    }
    endwin();
    std::cout << height << " " << width << std::endl;
    return (0);
}