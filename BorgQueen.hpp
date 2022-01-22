/*
** EPITECH PROJECT, 2022
** Day7
** File description:
** BorgQueen
*/

#ifndef BORGQUEEN_HPP_
#define BORGQUEEN_HPP_


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

namespace Borg
{
    class BorgQueen {
        public:
            BorgQueen();
            ~BorgQueen();
            bool (Borg::Ship::*movePtr)(Destination);
            void (Borg::Ship::*firePtr)(Federation::Starfleet::Ship *);
            void (Borg::Ship::*destroyPtr)(Federation::Ship *);
            bool move(Borg::Ship *, Destination);
            void fire(Borg::Ship *, Federation::Starfleet::Ship *);
            void destroy(Borg::Ship *, Federation::Ship *);
    };
}


#endif /* !BORGQUEEN_HPP_ */
