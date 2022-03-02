/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-tom.laumonier
** File description:
** Logger
*/

#include "Logger.hpp"

Logger::Logger() : Component("logger", 10)
{
    setAllPin(nts::Tristate::UNDEFINED);
}

Logger::~Logger()
{
}

void Logger::simulate(std::size_t tick)
{
    int addr = 0;
    std::string name = "log.bin";
    std::fstream file;

    UNUSED(tick);
    addr += _Pin[0] == nts::Tristate::TRUE ? 1 : 0;
    addr += _Pin[1] == nts::Tristate::TRUE ? 2 : 0;
    addr += _Pin[2] == nts::Tristate::TRUE ? 4 : 0;
    addr += _Pin[3] == nts::Tristate::TRUE ? 8 : 0;
    addr += _Pin[4] == nts::Tristate::TRUE ? 16 : 0;
    addr += _Pin[5] == nts::Tristate::TRUE ? 32 : 0;
    addr += _Pin[6] == nts::Tristate::TRUE ? 64 : 0;
    addr += _Pin[7] == nts::Tristate::TRUE ? 128 : 0;

    if (_Pin[8] == nts::Tristate::FALSE && _Pin[9] == nts::Tristate::TRUE)
        return;
    file.open(name, std::fstream::in | std::fstream::out | std::fstream::app);
    if (!file)
        file.open(name, std::fstream::in | std::fstream::out | std::fstream::trunc);
    file << (char)addr;
    file.close();
}