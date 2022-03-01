/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** NanoLoop
*/

#ifndef NANOLOOP_HPP_
#define NANOLOOP_HPP_

#include "NanoParser.hpp"
#include "Circuit.hpp"

class NanoLoop {
    public:
        NanoLoop();
        ~NanoLoop();
        void assignData(NanoParser &data);
        void start(void);
        std::string getInput(void);
        void checkCommand(std::string command);
        void execCommand(std::string command);
        void helpFunc(void);
        void exitFunc(void);
        void displayFunc(void);
        void displayInput(void);
        void displayOutput(void);
        void simulateFunc(void);
        void loopFunc(void);
        void dumpFunc(void);
        void inputFunc(std::string command);
        void printState(nts::Tristate state);
        nts::Tristate inputArgToTristate(std::string inputValue);

    protected:
        NanoParser _data;
        Circuit _circuit;
        size_t _tick;
    private:
};

#endif /* !NANOLOOP_HPP_ */
