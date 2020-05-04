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
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Originally Forked: Mario Talevski https://github.com/MarioTalevski/game-of-life
 * But the code has been massively refactored into classes,
 * so much that there is hardly any of the original code left unchanged.
 * I have marked the areas that did not change at all,
 * since those parts are not part of the above license or copyright.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// internal classes
#include "Util.h"
#include "GameOfLife.h"

using namespace GOL;

int main() {
    // clean the screen
    Util::clearScreen();
    // instantiate the game class on the heap
    auto *game = new GameOfLife;
    // print the intro message
    Util::introMessage(game);
    // play the game
    Util::run(game);
    // game has ended
    game->message->add("GAME ENDED");
    game->message->add("LINE")->print();
    // remove game from heap memory
    delete game;
    return 0;
}
