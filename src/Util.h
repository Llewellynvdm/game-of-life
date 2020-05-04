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

#ifndef GOL_UTIL_H
#define GOL_UTIL_H

// internal classes
#include "Game.h"
#include "GameOfLife.h"
#include "Message.h"
// libraries
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

namespace GOL {
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     *  I am trying out namespace just to see how it works :) any input would be great!
     *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    // class combine useful methods
    class Util {
    public:
        // force static use
        Util() = delete;
        // the introduction message
        static void introMessage(GameOfLife *game);

        // the infinity message
        static void infinityNote(GameOfLife *game);

        // the main method to run the game
        static void run(GameOfLife *game);

        // getting the coordinates for the board
        static void getCoordinates(GameOfLife *game);

        // method to clear the screen
        static void clearScreen();
    };
};

#endif //GOL_UTIL_H
