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
        class Error {
            public:
                enum ErrorType {
                    UNKNOWN,
                    PICTURE,
                    SPEAK
                };
                Error(const ErrorType &, std::string, std::string);
                Error();
                ~Error();
                std::string what() const;
                std::string const &where() const;
                void operator=(const Error &);
                ErrorType type;
            private:
                std::string error_msg;
                std::string where_str;
        };
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
        const Toy &operator=(const Toy &);
        virtual void speak(const std::string &);
        virtual bool speak_es(const std::string &);
        void operator<<(const std::string &);
        Error getLastError() const;
    protected:
        ToyType _type;
        std::string _name;
        Picture _ascii;
        Error _error;
    private:

};

std::ostream &operator<<(std::ostream &, const Toy &);

#endif /* !TOY_HPP_ */
