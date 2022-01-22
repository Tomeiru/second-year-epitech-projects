/*
** EPITECH PROJECT, 2022
** AM
** File description:
** Admiral
*/

#ifndef ADMIRAL_HPP_
#define ADMIRAL_HPP_

#include <iostream>

namespace Federation {
    namespace Starfleet {
        class Captain;
        class Ship;
        class Ensign;
    }
}

namespace Borg {
    class Ship;
}

#include "WarpSystem.hpp"
#include "Borg.hpp"
#include "Federation.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Admiral {
            public:
                Admiral(std::string);
                ~Admiral();
                bool (Federation::Starfleet::Ship::*movePtr)(Destination);
                void (Federation::Starfleet::Ship::*firePtr)(Borg::Ship *);
                void fire(Federation::Starfleet::Ship *, Borg::Ship *);
                bool move(Federation::Starfleet::Ship *, Destination);
            private:
                std::string _name;
        };
    }

}

#endif /* !ADMIRAL_HPP_ */
