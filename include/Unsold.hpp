/*
** EPITECH PROJECT, 2022
** 202unsold
** File description:
** Unsold
*/

#ifndef UNSOLD_HPP_
#define UNSOLD_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include "string.h"

class Unsold {
    public:
        Unsold(char *a, char *b);
        ~Unsold();
        void Calculate(void);
        void PrintUnsold(void);
        void CalculateTable(void);
        void CalculateZ(void);
        void CalculateLast(void);
    protected:
        double _a;
        double _b;
        std::vector<std::vector<double>> table;
        std::vector<double> z;
        std::vector<double> last;
    private:
};

#endif /* !UNSOLD_HPP_ */