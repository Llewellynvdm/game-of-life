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

#ifndef GOL_GAME_H
#define GOL_GAME_H

// internal classes
#include "color.h"
#include "Message.h"
// libraries
#include <iostream>
#include <string>

using namespace std;

namespace GOL {
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     *  I am trying out namespace just to see how it works :) any input would be great!
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    // class to manage game behaviour
    class Game {
    protected:
        // playing status
        bool play;
        // game color
        string color;
        // switch to stop board game
        bool active;

        // start the whole game
        void startPlaying();

        // set active state
        void setActive(bool active);

    public:
        // instantiate Message class pointer
        Message *message;

        // constructor
        Game() {
            // start playing
            startPlaying();
            // game color
            setColor(COLOR_GREEN);
            // set the board game to active
            setActive(true);
            // instantiate the message class on the heap as well
            message = new Message;
        }

        // destructor
        ~Game() {
            // remove message from heap memory
            delete message;
        }

        // set the game color
        void setColor(const string &color);

        // get the game color
        const string &getColor() const;

        // start the board game
        void start();

        // stop the board game
        void stop();

        // stop the whole game
        void stopPlaying();

        // are we still playing
        bool isStillPlaying() const;

        // check if we are still active
        bool isActive() const;

    };
}


#endif //GOL_GAME_H
