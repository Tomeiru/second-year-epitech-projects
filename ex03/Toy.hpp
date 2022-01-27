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
            BUZZ,
            WOODY
        };
        Toy(const ToyType &, const std::string &, const std::string &);
        Toy(const Toy &);
        Toy();
        ~Toy();
        ToyType getType() const;
        std::string getName() const;
        std::string getAscii() const;
        bool setAscii(const std::string &);
        void setName(const std::string &);
        void operator=(const Toy &);
        virtual void speak(const std::string &);
    protected:
        ToyType _type;
        std::string _name;
        Picture _ascii;
    private:

};

#endif /* !TOY_HPP_ */
