/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** Jobs
*/

#pragma once

#include <queue>
#include <iostream>
#include <memory>
#include "CThread.hpp"
#include "../mutex/CMutex.hpp"
#include "../mutex/ScopeLock.hpp"

namespace plazza {
    class IJob {
        public:
        virtual void execute() = 0;
    };

    class Jobs {
        std::queue<std::unique_ptr<IJob>> _jobs;
        CMutex _lock;

        public:
        void addJob(std::unique_ptr<IJob> &job);
        std::unique_ptr<IJob> getJob();
        size_t getSize() const;
    };
}
