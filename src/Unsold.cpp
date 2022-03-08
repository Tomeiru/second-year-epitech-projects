/*
** EPITECH PROJECT, 2022
** 202unsold
** File description:
** Unsold
*/

#include "Error.hpp"

Unsold::Unsold(char *a, char *b)
{
    std::string a_string = a;
    std::string b_string = b;
    size_t a_int = 0;
    size_t b_int = 0;
    try {
        a_int = std::stol(a_string);
        b_int = std::stol(b_string);
        _a = a_int;
        _b = b_int;
    }
    catch (std::exception const &error) {
        throw UnsoldError(error.what());
    }
    if (a_int <= 50 || b_int <= 50)
        throw UnsoldError("Value equal or below to 50");
}

Unsold::~Unsold()
{
}

void Unsold::CalculateTable(void)
{
    for (size_t i = 1; i < 6; i++) {
        std::vector<double> line;
        double total = 0;
        double y = i * 10;
        for (size_t ii = 1; ii < 6; ii++) {
            double x = ii * 10;
            double value = ((_a - x)*(_b - y))/((5.f * _a - 150.f)*(5.f * _b - 150.f));
            line.push_back(value);
            total += value;
        }
        line.push_back(total);
        table.push_back(line);
    }
    std::vector<double> line;
    double total = 0;
    for (size_t i = 0; i < table[i].size(); i++) {
        double new_value = 0;
        for (size_t ii = 0; ii < table.size(); ii++) {
            new_value += table[ii][i];
        }
        line.push_back(new_value);
        total += new_value;
    }
    line.push_back(total);
    table.push_back(line);
}

void Unsold::CalculateZ(void)
{
    double value = table[0][0];
    z.push_back(value);
    value = table[0][1] + table[1][0];
    z.push_back(value);
    value = table[0][2] + table[1][1] + table[2][0];
    z.push_back(value);
    value = table[0][3] + table[3][0] + table[1][2] + table[2][1];
    z.push_back(value);
    value = table[0][4] + table[1][3] + table[2][2] + table[3][1] + table[4][0];
    z.push_back(value);
    value = table[1][4] + table[2][3] + table[3][2] + table[4][1];
    z.push_back(value);
    value = table[2][4] + table[3][3] + table[4][2];
    z.push_back(value);
    value = table[3][4] + table[4][3];
    z.push_back(value);
    value = table[4][4];
    z.push_back(value);
}

void Unsold::CalculateLast(void)
{
    last.push_back(table[5][0] * 10.f + table[5][1] * 20.f + table[5][2] * 30.f + table[5][3] * 40.f + table[5][4] * 50.f);
    last.push_back((table[5][0] * 100.f + table[5][1] * 400.f + table[5][2] * 900.f + table[5][3] * 1600.f + table[5][4] * 2500.f) - (last[0] * last[0]));
    last.push_back(table[0][5] * 10.f + table[1][5] * 20.f + table[2][5] * 30.f + table[3][5] * 40.f + table[4][5] * 50.f);
    last.push_back((table[0][5] * 100.f + table[1][5] * 400.f + table[2][5] * 900.f + table[3][5] * 1600.f + table[4][5] * 2500.f) - (last[2] * last[2]));
    last.push_back(last[0] + last[2]);
    last.push_back(last[1] + last[3]);
}

void Unsold::Calculate(void)
{
    CalculateTable();
    CalculateZ();
    CalculateLast();
}

void Unsold::PrintUnsold(void)
{
    printf("--------------------------------------------------------------------------------\n");
    printf("        X=10    X=20    X=30    X=40    X=50    Y law\n");
    printf("Y=10    %.3f   %.3f   %.3f   %.3f   %.3f   %.3f\n", table[0][0], table[0][1], table[0][2], table[0][3], table[0][4], table[0][5]);
    printf("Y=20    %.3f   %.3f   %.3f   %.3f   %.3f   %.3f\n", table[1][0], table[1][1], table[1][2], table[1][3], table[1][4], table[1][5]);
    printf("Y=30    %.3f   %.3f   %.3f   %.3f   %.3f   %.3f\n", table[2][0], table[2][1], table[2][2], table[2][3], table[2][4], table[2][5]);
    printf("Y=40    %.3f   %.3f   %.3f   %.3f   %.3f   %.3f\n", table[3][0], table[3][1], table[3][2], table[3][3], table[3][4], table[3][5]);
    printf("Y=50    %.3f   %.3f   %.3f   %.3f   %.3f   %.3f\n", table[4][0], table[4][1], table[4][2], table[4][3], table[4][4], table[4][5]);
    printf("X law   %.3f   %.3f   %.3f   %.3f   %.3f   %.3f\n", table[5][0], table[5][1], table[5][2], table[5][3], table[5][4], table[5][5]);
    printf("--------------------------------------------------------------------------------\n");
    printf("z       20      30      40      50      60      70      80      90      100\n");
    printf("p(Z=z)  %.3f   %.3f   %.3f   %.3f   %.3f   %.3f   %.3f   %.3f   %.3f\n", z[0], z[1], z[2], z[3], z[4], z[5], z[6], z[7], z[8]);
    printf("--------------------------------------------------------------------------------\n");
    printf("expected value of X:    %.1f\n", last[0]);
    printf("variance of X:          %.1f\n", last[1]);
    printf("expected value of Y:    %.1f\n", last[2]);
    printf("variance of Y:          %.1f\n", last[3]);
    printf("expected value of Z:    %.1f\n", last[4]);
    printf("variance of Z:          %.1f\n", last[5]);
    printf("--------------------------------------------------------------------------------\n");
}