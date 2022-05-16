/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** Jobs
*/

#pragma once

#include <vector>
#include <iostream>

namespace plazza {
    struct Job
    {
        CThreadFct func;
        void *arg;
    };

    class Jobs {
    std::vector<Job> _jobs;

        public:
            Jobs();
            ~Jobs();

            void addJob(Job job);
            Job jobDone();
            std::vector<Job> getJobs() const;
            size_t getSize() const;
    };
}
