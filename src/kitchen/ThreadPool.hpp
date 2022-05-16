/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** ThreadPool
*/

#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "../thread/CThread.hpp"
#include "../mutex/IMutex.hpp"
#include "../cond/ICondVar.hpp"
#include "Jobs.hpp"

namespace plazza {
    struct PoolArg
    {
        Jobs jobs;
        std::unique_ptr<ICondVar> condToDo;
    };

    class ThreadPool {
        Jobs _jobs;
        unsigned int _size;
        std::unique_ptr<ICondVar> _condToDo;
        std::vector<CThread> _threadTab;

        public:
            ThreadPool(unsigned int threadNbr);
            ~ThreadPool();

            void addJob(Job job);
    };
}
