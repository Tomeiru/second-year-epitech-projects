/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** Or_4071
*/

#ifndef OR_4071_HPP_
#define OR_4071_HPP_

#include "Component.hpp"

class Or_4071 : public Component{
    public:
        Or_4071(std::string name);
        ~Or_4071();
        void simulate(std::size_t tick);
    protected:
    private:
};

#endif /* !OR_4071_HPP_ */
