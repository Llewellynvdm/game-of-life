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

#ifndef GOL_GAMEOFLIFE_H
#define GOL_GAMEOFLIFE_H

#include "Game.h"

namespace GOL {
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     *  I am trying out namespace just to see how it works :) any input would be great!
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    class GameOfLife : public Game {
    private:
        // the board game size
        static const int boardSize = 30;
        // hidden size to center the view
        static const int center = boardSize * 4;
        // hidden size to be able to move gliders and ships out of view
        static const int size = boardSize * 9;
        // active state arrays
        bool activeState[size][size] = {};
        bool previousState[size][size] = {};
        // has infinity been set?
        bool infinitySet;
        signed long infinityCounter;
        // infinity switches
        bool activeInfinity;

        // copy the active state to the previous state array
        void copyState();

    public:

        // constructor
        GameOfLife() {
            // turn off infinity
            setActiveInfinity(false);
            setInfinity(false);
            setInfinityCounter(0);
        }

        // destructor
        ~GameOfLife() {}

        // set the active coordinates
        void set(int x, int y);

        // unset any coordinates
        void unset(int x, int y);

        // reset the board
        void reset();

        // print the board with active coordinates
        void print(int action = 1);

        // set the board active state
        void setState();

        // get view board size
        int getViewSize();

        // get view board area
        int getViewArea();

        // get settable board area
        int getSettableArea();

        // check if infinity is set
        bool isInfinitySet() const;

        // set infinity
        void setInfinity(bool infinitySet);

        // check if infinity is active
        bool isActiveInfinity() const;

        // set the infinity active state
        void setActiveInfinity(bool activeInfinity);

        // get the infinity counter value
        long getInfinityCounter() const;

        // set the infinity counter value
        void setInfinityCounter(long infinity);

        // decrement infinity counter value
        void decrementInfinity();
    };

}


#endif //GOL_GAMEOFLIFE_H
