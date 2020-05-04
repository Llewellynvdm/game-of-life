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

#include "GameOfLife.h"

namespace GOL {
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     *  I am trying out namespace just to see how it works :) any input would be great!
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    // set the active coordinate
    void GameOfLife::set(int x, int y) {
        GameOfLife::activeState[x + GameOfLife::center][y + GameOfLife::center] = true;
    }

    // unset any coordinate
    void GameOfLife::unset(int x, int y) {
        GameOfLife::activeState[x + GameOfLife::center][y + GameOfLife::center] = false;
    }

    // reset the board
    void GameOfLife::reset() {
        for (int x = 0; x < GameOfLife::size; x++) {
            for (int y = 0; y < GameOfLife::size; y++) {
                GameOfLife::previousState[x][y] = false;
                GameOfLife::activeState[x][y] = false;
            }
        }
        // any moment reset is called we also re-start the game internally
        this->start();
        // do some house cleaning resets
        this->setActiveInfinity(false);
        this->setInfinityCounter(0);
        this->setInfinity(false);
    }

    // print the board with active coordinates
    void GameOfLife::print(int action) {
        if (this->isActive()) {
            // make sure we stay in same color
            cout << this->getColor();
            // stop game if all are dead
            if (action == 1) {
                this->stop();
            }
            // loop over the y axis
            for (int y = GameOfLife::boardSize; y > 0; y--) {
                // loop over the x axis
                for (int x = 1; x < GameOfLife::boardSize; x++) {
                    if (x == 1) {
                        // add line numbers
                        if (action == 3) {
                            if (y < 10) {
                                cout << y << " ";
                            } else {
                                cout << y;
                            }
                        } else {
                            cout << "   ";
                        }
                    }
                    // check if a cell is active/alive
                    if (GameOfLife::activeState[x + GameOfLife::center][y + GameOfLife::center]) {
                        cout << " O ";
                        // check if one cell in view is still active (and not still)
                        if (!GameOfLife::previousState[x + GameOfLife::center][y + GameOfLife::center] ||
                            this->isActiveInfinity()) {
                            // if this is infinity
                            if (this->isActiveInfinity()) {
                                this->decrementInfinity();
                            }
                            this->start();
                        }
                    } else {
                        cout << " . ";
                    }
                    // print end of line when at the end of line
                    if (x == GameOfLife::boardSize - 1) {
                        cout << endl;
                    }
                }
            }
            // add bottom line of numbers if needed
            if (action == 3) {
                cout << "  ";
                for (int x = 1; x < GameOfLife::boardSize; x++) {
                    if (x < 10) {
                        cout << " " << x << " ";
                    } else {
                        cout << " " << x;
                    }
                }
                cout << endl;
            }
            // if this is infinity
            if (action == 1 && this->isActiveInfinity() && this->getInfinityCounter() < 0) {
                // when the preset infinity controller switches
                // reach its conclusion stop the game
                // so the player can choose another pattern
                this->stop();
            }
        }
    }

    // copy the active state to the previous state array
    void GameOfLife::copyState() {
        // loop over the entire x axis of the board
        for (int x = 0; x < GameOfLife::size; x++) {
            // loop over the entire y axis of the board
            for (int y = 0; y < GameOfLife::size; y++) {
                // copy the value over to the previous state
                GameOfLife::previousState[x][y] = GameOfLife::activeState[x][y];
            }
        }
    }

    // set the board active state
    void GameOfLife::setState() {
        // make sure we have the active state copied
        this->copyState();
        // check every cell on the board
        // loop over the entire x axis of the board
        for (int x = 1; x < GameOfLife::size; x++) {
            // loop over the entire y axis of the board
            for (int y = 1; y < GameOfLife::size; y++) {
                int alive = 0;
                // loop to check all eight neighbours
                // . . .
                // . 0 .
                // . . .
                // the dots are the neighbours
                // zero is the active cell
                for (int x2 = -1; x2 < 2; x2++) { // this loop increments the x axis lookup
                    for (int y2 = -1; y2 < 2; y2++) { // this loop increments the y axis lookup
                        // when x and y are 0 then
                        // do not check since it is
                        // the current active cell
                        if (!(x2 == 0 && y2 == 0)) {
                            // check if this neighbour was alive
                            if (GameOfLife::previousState[x + x2][y + y2]) {
                                // when alive we increment the alive value
                                // which we later will use to act upon
                                ++alive;
                            }
                        }
                    }
                }
                // now let's act upon the alive status
                if (alive < 2) {
                    // Any live cell with fewer than two live neighbours dies, as if caused by under-population.
                    // what ever that means...
                    GameOfLife::activeState[x][y] = false;
                } else if (alive == 3) {
                    // Any live cell with three live neighbours lives on to the next generation.
                    // what ever that means...
                    GameOfLife::activeState[x][y] = true;
                } else if (alive > 3) {
                    // Any live cell with more than three live neighbours dies, as if by over-population.
                    // Which is not true, I have eight children and a very bright future!!!
                    // We were made to be fruitful Genesis 1:28 (in real Life)
                    // but in this game...
                    GameOfLife::activeState[x][y] = false;
                }
            }
        }
    }

    // get view board size
    int GameOfLife::getViewSize() {
        // return string
        return GameOfLife::boardSize;
    }

    // get view board size
    int GameOfLife::getViewArea() {
        return GameOfLife::boardSize * GameOfLife::boardSize;
    }

    // get settable board area
    int GameOfLife::getSettableArea() {
        return GameOfLife::boardSize * 3;
    }

    // check if infinity is set
    bool GameOfLife::isInfinitySet() const {
        return GameOfLife::infinitySet;
    }

    // set infinity
    void GameOfLife::setInfinity(bool infinitySet) {
        GameOfLife::infinitySet = infinitySet;
    }

    // check if infinity is active
    bool GameOfLife::isActiveInfinity() const {
        return activeInfinity;
    }

    // set the infinity active state
    void GameOfLife::setActiveInfinity(bool activeInfinity) {
        GameOfLife::activeInfinity = activeInfinity;
    }

    // get the infinity counter value
    long GameOfLife::getInfinityCounter() const {
        return GameOfLife::infinityCounter;
    }

    // set the infinity counter value
    void GameOfLife::setInfinityCounter(long infinity) {
        GameOfLife::infinityCounter = infinity;
    }

    // decrement infinity counter value
    void GameOfLife::decrementInfinity() {
        GameOfLife::infinityCounter--;
    }
}