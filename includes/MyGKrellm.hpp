/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** MyGKrellm
*/

#ifndef MYGKRELLM_HPP_
#define MYGKRELLM_HPP_

#include <iostream>
#include <exception>
#include <cstring>
#include <ncurses.h>
#include <unistd.h>
#include <sys/utsname.h>
#include "MyGKrellmInfo.hpp"

void argumentCheck(int ac, char **av);
int startCurses(MyGKrellmInfo *info);

/*class MyGKrellm {
    public:
        MyGKrellm();
        ~MyGKrellm();

    protected:
    private:
};*/

#endif /* !MYGKRELLM_HPP_ */