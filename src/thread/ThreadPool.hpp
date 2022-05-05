/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** ThreadPool
*/

#pragma once

#include <iostream>
#include <deque>
#include "CThread.hpp"

namespace plazza {
    class SecuredThread : public CThread {
        pthread_t _thread;
        bool _joined;

        public:
            SecuredThread(CThreadFct fct, void *arg);
            ~SecuredThread();

            bool isJoined() const;
            void join();
    };

    class ThreadPool {
        std::deque<SecuredThread> _threadTab;
        unsigned int _lastThread;

        public:
            ThreadPool();
            ~ThreadPool();

            void join();
            void add_thread(CThreadFct fct, void *arg);
            void goNext() {if ((_lastThread+1) < _threadTab.size()) _lastThread++;};
    };
}
