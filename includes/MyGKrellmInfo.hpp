/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** MyGKrellmInfo
*/

#ifndef MYGKRELLMINFO_HPP_
#define MYGKRELLMINFO_HPP_

class MyGKrellmInfo {
    public:
        MyGKrellmInfo(char **);
        ~MyGKrellmInfo();
        std::string getHostname();
        std::string getUsername();
        std::string getOS();
        std::string getKernelVersion();
        std::string getDateTime();
        void refreshDateTime();
        void printInfo();
    protected:
        std::string hostname;
        std::string username;
        std::string OS;
        std::string kernelVersion;
        std::string dateTime;
    private:
};

#endif /* !MYGKRELLMINFO_HPP_ */
