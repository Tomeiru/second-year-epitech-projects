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
        void addToQueue(std::string command);
        void clearQueue(void);
        void setStatefromLink(std::tuple<std::string, size_t, std::string, size_t> link, bool first);
        void setStateGate(std::string nameGet, size_t pinGet, std::string nameSet, size_t pinSet);
        void getLinkLine(std::string nameGet, size_t pinGet);
        void setStateInverter(std::string nameGet, size_t pinGet, std::string nameSet, size_t pinSet);
        void setStateAdder(std::string nameGet, size_t pinGet, std::string nameSet, size_t pinSet);
        void setStateFlipFlop(std::string nameGet, size_t pinGet, std::string nameSet, size_t pinSet);
        void setStateJohnson(std::string nameGet, size_t pinGet, std::string nameSet, size_t pinSet);
        void setStateCounter(std::string nameGet, size_t pinGet, std::string nameSet, size_t pinSet);
        void setStateShift(std::string nameGet, size_t pinGet, std::string nameSet, size_t pinSet);
        void setStateSelector(std::string nameGet, size_t pinGet, std::string nameSet, size_t pinSet);
        void setStateDecoder(std::string nameGet, size_t pinGet, std::string nameSet, size_t pinSet);
    protected:
        NanoParser _data;
        Circuit _circuit;
        size_t _tick;
        std::vector<std::string> _queue;
    private:
};

#endif /* !NANOLOOP_HPP_ */
