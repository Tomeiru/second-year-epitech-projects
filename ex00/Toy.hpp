/*
** EPITECH PROJECT, 2022
** Day11
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Picture.hpp"

class Toy {
    public:
        enum ToyType {
        BASIC_TOY,
        ALIEN,
        };
        Toy(ToyType, std::string, std::string);
        Toy();
        ~Toy();
        ToyType getType() const;
        std::string getName() const;
        std::string getAscii() const;
        void setAscii(std::string);
        void setName(std::string);
    protected:
    private:
        ToyType _type;
        std::string _name;
        Picture _ascii;

};

#endif /* !TOY_HPP_ */
