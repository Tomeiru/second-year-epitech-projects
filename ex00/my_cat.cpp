/*
** EPITECH PROJECT, 2022
** Day6
** File description:
** my_cat
*/

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    std::string name;

    if (ac == 1) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return (0);
    }for (int i = 1; i < ac; i++) {
        name = av[i];
        std::ifstream file(name);
        if (file.is_open())
            std::cout << file.rdbuf();
        else
            std::cerr << "my_cat: " << name <<
            ": No such file or directory" << std::endl;
    }
    return (0);
}