/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** myftp
*/

#pragma once

//INCLUDES

#include <arpa/inet.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>

//PROTOTYPES

int print_error(char *err);
int myftp(char **args);
char *check_and_get_path(char *path);
int check_and_get_port(char *port);

//DEFINES

#define UNUSED(x) (void)(x)