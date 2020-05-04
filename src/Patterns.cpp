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
#include "Patterns.h"
#include "GameOfLife.h"
// libraries
#include <map>
#include <string>

using namespace std;

namespace GOL {
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     *  I am trying out namespace just to see how it works :) any input would be great!
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    // set the preset pattern
    bool Patterns::setPreset(int pattern, GameOfLife *game) {
        // we have the infinity stuff set
        game->setInfinity(true);
        // default means pattern does not yet exist
        switch (pattern) {
            case 1:
                return this->testBoard(game);
            case 2:
                return this->blinker(game);
            case 3:
                return this->toad(game);
            case 4:
                return this->beacon(game);
            case 5:
                return this->pulsar(game);
            case 6:
                return this->pentaDecathlon(game);
            case 7:
                return this->gliderGun(game);
            case 8:
                return this->glidersEaters(game);
            case 9:
                return this->glider(game);
            case 10:
                return this->lightWeightSpaceship(game);
            case 11:
                return this->middleWeightSpaceship(game);
            case 12:
                return this->heavyWeightSpaceship(game);
            default:
                game->setInfinity(false);
                return false;
        }
    }

    // set the preset pattern
    map<int, string> Patterns::getPresets() {
        map<int, string> presets;
        presets[1] = "Test Board (fun)";
        presets[2] = "Blinker (Oscillator - infinity)";
        presets[3] = "Toad (Oscillator - infinity)";
        presets[4] = "Beacon (Oscillator - infinity)";
        presets[5] = "Pulsar (Oscillator - infinity)";
        presets[6] = "Penta-decathlon (Oscillator - infinity)";
        presets[7] = "Glider Gun (fun)";
        presets[8] = "Gliders Eaters (fun)";
        presets[9] = "Glider (Spaceship)";
        presets[10] = "Light Weight (Spaceship)";
        presets[11] = "Middle Weight (Spaceship)";
        presets[12] = "Heavy Weight (Spaceship)";
        return presets;
    }

    // set the test board pattern
    bool Patterns::testBoard(GameOfLife *game) {
        game->set(11, 12);
        game->set(11, 14);
        game->set(11, 13);
        game->set(12, 13);
        game->set(13, 12);
        // deal with infinity
        game->setActiveInfinity(false);
        game->setInfinityCounter(0);
        return true;
    }

    // set the blinker pattern
    bool Patterns::blinker(GameOfLife *game) {
        game->set(5, 5);
        game->set(5, 6);
        game->set(5, 7);
        // deal with infinity
        game->setActiveInfinity(true);
        game->setInfinityCounter(3 * 20);
        return true;
    }

    // set the toad pattern
    bool Patterns::toad(GameOfLife *game) {
        game->set(4, 7);
        game->set(5, 5);
        game->set(5, 8);
        game->set(6, 5);
        game->set(6, 8);
        game->set(7, 6);
        // deal with infinity
        game->setActiveInfinity(true);
        game->setInfinityCounter(6 * 20);
        return true;
    }

    // set the beacon pattern
    bool Patterns::beacon(GameOfLife *game) {
        game->set(4, 5);
        game->set(4, 6);
        game->set(5, 5);
        game->set(6, 8);
        game->set(7, 8);
        game->set(7, 7);
        // deal with infinity
        game->setActiveInfinity(true);
        game->setInfinityCounter(6 * 20);
        return true;
    }

    // set the pulsar pattern
    bool Patterns::pulsar(GameOfLife *game) {
        // outer rings
        game->set(8, 6);
        game->set(9, 6);
        game->set(10, 6);

        game->set(14, 6);
        game->set(15, 6);
        game->set(16, 6);

        game->set(18, 8);
        game->set(18, 9);
        game->set(18, 10);

        game->set(18, 14);
        game->set(18, 15);
        game->set(18, 16);

        game->set(6, 8);
        game->set(6, 9);
        game->set(6, 10);

        game->set(6, 14);
        game->set(6, 15);
        game->set(6, 16);

        game->set(8, 18);
        game->set(9, 18);
        game->set(10, 18);

        game->set(14, 18);
        game->set(15, 18);
        game->set(16, 18);

        // inner rings
        game->set(8, 11);
        game->set(9, 11);
        game->set(10, 11);

        game->set(14, 11);
        game->set(15, 11);
        game->set(16, 11);

        game->set(13, 8);
        game->set(13, 9);
        game->set(13, 10);

        game->set(13, 14);
        game->set(13, 15);
        game->set(13, 16);

        game->set(11, 8);
        game->set(11, 9);
        game->set(11, 10);

        game->set(11, 14);
        game->set(11, 15);
        game->set(11, 16);

        game->set(8, 13);
        game->set(9, 13);
        game->set(10, 13);

        game->set(14, 13);
        game->set(15, 13);
        game->set(16, 13);
        // deal with infinity
        game->setActiveInfinity(true);
        game->setInfinityCounter(5 * 600);
        return true;
    }

    // set the Penta-decathlon pattern
    bool Patterns::pentaDecathlon(GameOfLife *game) {
        // top
        game->set(3, 12);
        game->set(4, 12);
        game->set(5, 12);
        game->set(5, 11);
        game->set(5, 13);

        // middle
        game->set(13, 11);
        game->set(13, 13);
        game->set(13, 12);
        game->set(12, 12);
        game->set(11, 12);
        game->set(10, 12);
        game->set(9, 12);
        game->set(8, 12);
        game->set(8, 11);
        game->set(8, 13);

        // bottom
        game->set(18, 12);
        game->set(17, 12);
        game->set(16, 12);
        game->set(16, 11);
        game->set(16, 13);

        // deal with infinity
        game->setActiveInfinity(true);
        game->setInfinityCounter(5 * 350);
        return true;
    }

    // set the glider pattern
    bool Patterns::glider(GameOfLife *game) {
        game->set(2, 3);
        game->set(3, 4);
        game->set(4, 2);
        game->set(4, 3);
        game->set(4, 4);
        // deal with infinity
        game->setActiveInfinity(false);
        game->setInfinityCounter(0);
        return true;
    }

    // set the glider gun pattern
    bool Patterns::gliderGun(GameOfLife *game) {
        // first square
        game->set(-2, 26);
        game->set(-2, 25);
        game->set(-3, 26);
        game->set(-3, 25);

        // first after
        game->set(7, 26);
        game->set(7, 25);
        game->set(7, 24);
        game->set(8, 27);
        game->set(8, 23);
        game->set(9, 28);
        game->set(9, 22);
        game->set(10, 28);
        game->set(10, 22);
        game->set(11, 25);
        game->set(12, 27);
        game->set(12, 23);
        game->set(13, 26);
        game->set(13, 25);
        game->set(13, 24);
        game->set(14, 25);

        // second after
        game->set(17, 28);
        game->set(17, 27);
        game->set(17, 26);
        game->set(18, 28);
        game->set(18, 27);
        game->set(18, 26);
        game->set(19, 29);
        game->set(19, 25);
        game->set(21, 29);
        game->set(21, 30);
        game->set(21, 25);
        game->set(21, 24);

        // last square
        game->set(31, 26);
        game->set(31, 27);
        game->set(32, 26);
        game->set(32, 27);

        // deal with infinity
        game->setActiveInfinity(true);
        game->setInfinityCounter(5 * 2000);
        return true;
    }

    // set the light weight spaceship pattern
    bool Patterns::lightWeightSpaceship(GameOfLife *game) {
        game->set(5, 4);
        game->set(5, 5);
        game->set(6, 2);
        game->set(6, 3);
        game->set(6, 5);
        game->set(6, 6);
        game->set(7, 2);
        game->set(7, 3);
        game->set(7, 4);
        game->set(7, 5);
        game->set(8, 3);
        game->set(8, 4);
        // deal with infinity
        game->setActiveInfinity(false);
        game->setInfinityCounter(0);
        return true;
    }

    // set the middle weight spaceship pattern
    bool Patterns::middleWeightSpaceship(GameOfLife *game) {
        game->set(2, 10);
        game->set(2, 12);
        game->set(3, 9);
        game->set(4, 9);
        game->set(4, 13);
        game->set(5, 9);
        game->set(6, 9);
        game->set(6, 12);
        game->set(7, 9);
        game->set(7, 10);
        game->set(7, 11);
        // deal with infinity
        game->setActiveInfinity(false);
        game->setInfinityCounter(0);
        return true;
    }

    // set the heavy weight spaceship pattern
    bool Patterns::heavyWeightSpaceship(GameOfLife *game) {
        game->set(2, 10);
        game->set(2, 12);
        game->set(3, 9);
        game->set(4, 9);
        game->set(4, 13);
        game->set(5, 9);
        game->set(5, 13);
        game->set(6, 9);
        game->set(7, 9);
        game->set(7, 12);
        game->set(8, 9);
        game->set(8, 10);
        game->set(8, 11);
        // deal with infinity
        game->setActiveInfinity(false);
        game->setInfinityCounter(0);
        return true;
    }

    // set the gliders eaters pattern
    bool Patterns::glidersEaters(GameOfLife *game) {
        // top left
        game->set(5, 3);
        game->set(5, 4);
        game->set(6, 4);
        game->set(7, 4);
        game->set(8, 5);
        game->set(8, 6);
        game->set(7, 6);

        // bottom left
        game->set(13, 4);
        game->set(14, 4);
        game->set(15, 4);
        game->set(15, 3);
        game->set(12, 5);
        game->set(12, 6);
        game->set(13, 6);

        // top right
        game->set(7, 19);
        game->set(8, 19);
        game->set(8, 20);
        game->set(7, 21);
        game->set(6, 21);
        game->set(5, 21);
        game->set(5, 22);

        // bottom right
        game->set(13, 19);
        game->set(12, 19);
        game->set(12, 20);
        game->set(13, 21);
        game->set(14, 21);
        game->set(15, 21);
        game->set(15, 22);

        // center top
        game->set(9, 10);
        game->set(9, 15);

        // center middle
        game->set(10, 8);
        game->set(10, 9);
        game->set(10, 11);
        game->set(10, 12);
        game->set(10, 13);
        game->set(10, 14);
        game->set(10, 16);
        game->set(10, 17);

        // center bottom
        game->set(11, 10);
        game->set(11, 15);
        // deal with infinity
        game->setActiveInfinity(true);
        game->setInfinityCounter(5 * 605);
        return true;
    }
}