/*
** EPITECH PROJECT, 2022
** Day11
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <iostream>
#include <fstream>
#include <sstream>

class Picture {
    public:
        Picture(const std::string &);
        Picture();
        ~Picture();
        std::string _data;
        bool getPictureFromFile(const std::string &file);

    protected:
    private:
};

#endif /* !PICTURE_HPP_ */
