/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** NanoLoop
*/

#ifndef NANOLOOP_HPP_
#define NANOLOOP_HPP_

#include "NanoParser.hpp"

class NanoLoop {
    public:
        NanoLoop();
        ~NanoLoop();
        void assignData(NanoParser &data);
        void start(void);
        std::string getInput(void);
        bool checkCommand(std::string command);
        void execCommand(std::string command);

    protected:
        NanoParser _data;
    private:
};

void helpFunc(void);
void exitFunc(void);
void displayFunc(void);
void simulateFunc(void);
void loopFunc(void);
void dumpFunc(void);
void inputFunc(std::string state);

#endif /* !NANOLOOP_HPP_ */
