/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-240-81A
 *
 * C++ Final Project (first semester) - Coding Component  (2020/05/02)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * This is a demonstration in C++ of a game called
 * Game of life created by John Horton Conway in 1970
 * https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Written by Llewellyn van der Merwe <llewellyn.vandermerw@mymail.champlain.edu>, April 2020
 * Copyright (C) 2020. All Rights Reserved
 * License GNU/GPL Version 2 or later - http://www.gnu.org/licenses/gpl-2.0.html
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef GOL_PATTERNS_H
#define GOL_PATTERNS_H

// internal classes
#include "GameOfLife.h"
// libraries
#include <iostream>
#include <map>
#include <string>

using namespace std;

namespace GOL {
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     *  I am trying out namespace just to see how it works :) any input would be great!
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    // class to set all board patterns
    class Patterns {
    private:
        // all the patterns
        bool testBoard(GameOfLife *game);

        bool blinker(GameOfLife *game);

        bool toad(GameOfLife *game);

        bool beacon(GameOfLife *game);

        bool pulsar(GameOfLife *game);

        bool pentaDecathlon(GameOfLife *game);

        bool gliderGun(GameOfLife *game);

        bool glidersEaters(GameOfLife *game);

        bool glider(GameOfLife *game);

        bool lightWeightSpaceship(GameOfLife *game);

        bool middleWeightSpaceship(GameOfLife *game);

        bool heavyWeightSpaceship(GameOfLife *game);

    public:
        // set the preset pattern
        bool setPreset(int pattern, GameOfLife *game);

        // get the preset pattern list
        static map<int, string> getPresets();
    };
}

#endif //GOL_PATTERNS_H
