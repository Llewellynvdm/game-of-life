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

// internal classes
#include "Game.h"
// libraries
#include <iostream>

using namespace std;

namespace GOL {
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     *  I am trying out namespace just to see how it works :) any input would be great!
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    // check if we are still active
    bool Game::isActive() const {
        return Game::active;
    }

    // set game active state
    void Game::setActive(bool active) {
        Game::active = active;
    }

    // stop the board game
    void Game::stop() {
        this->setActive(false);
    }

    // start the board game
    void Game::start() {
        this->setActive(true);
    }

    // check if player is still playing
    bool Game::isStillPlaying() const {
        return Game::play;
    }

    // stop the whole game
    void Game::stopPlaying() {
        Game::play = false;
    }

    // start the whole game
    void Game::startPlaying() {
        Game::play = true;
    }

    // get the game color
    const string &Game::getColor() const {
        return Game::color;
    }

    void Game::setColor(const string &color) {
        Game::color = color;
    }
}