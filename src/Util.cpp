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
#include "Util.h"
#include "GameOfLife.h"
#include "Patterns.h"
#include "Message.h"
#include "GetInput.h"
// libraries
#include <iostream>

using namespace std;

namespace GOL {
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     *  I am trying out namespace just to see how it works :) any input would be great!
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    // the introduction message
    void Util::introMessage(GameOfLife *game) {
        game->message->add("LINE");
        game->message->add("This is a demonstration in C++ of a game called");
        game->message->add("Game of life created by John Horton Conway in 1970");
        game->message->add("https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life");
        game->message->add("LINE");
        game->message->add("Written by Llewellyn van der Merwe");
        game->message->add("LINE");
        game->message->add("The Rules");
        game->message->add("At each step in time, the following transitions occur:");
        game->message->add("1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.");
        game->message->add("2. Any live cell with two or three live neighbours lives on to the next generation.");
        game->message->add("3. Any live cell with more than three live neighbours dies, as if by overpopulation.");
        game->message->add("4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.");
        game->message->add("LINE")->print(0);
    }

    // getting the coordinates for the board
    void Util::getCoordinates(GameOfLife *game) {
        // lets make sure our board is clean
        game->reset();
        // instantiate x and y to be integers
        int x, y;
        // setup the question
        game->message->add("This game has the following input options");
        game->message->add("LINE");
        game->message->add("1. Select a pattern from our presets.");
        game->message->add("2. Enter a path to a file with the coordinates.");
        game->message->add("3. Manually add coordinates to the board.");
        game->message->add("or 'q' to quit")->print(0);
        // get the user path to action
        GetInput action(game->message->ask("Enter your selection: "));
        // clean the screen
        Util::clearScreen();
        game->message->add("LINE");
        // file or preset was selected
        if (action.get() == "2") {
            // clean the screen
            Util::clearScreen();
            while (true) {
                // give info of the coordinates convention
                game->message->add("Coordinates must be given in the following way");
                game->message->add("LINE");
                game->message->add("Each line must have two numbers separated by a space.");
                game->message->add("The first number is the x axis value, and the second number is the y axis value.");
                game->message->add("So each line represents a coordinate/cell on the board that is active/alive.");
                game->message->add("The view area of the board has " +
                            to_string(game->getViewSize()) + " x " +
                            to_string(game->getViewSize()) + " = " +
                            to_string(game->getViewArea()) + " cells. But the board is far larger.");
                game->message->add("Meaning you are able to add negative and positive values to a depth of -" +
                            to_string(game->getSettableArea()) + " and " +
                            to_string(game->getSettableArea()) + ".")->print();
                // get the file path
                GetInput filepath(game->message->ask("Enter file path to read coordinates from, or 'b' to go back: "));
                // check if the player want to go back
                if (filepath.get() == "b") {
                    // go back
                    getCoordinates(game);
                    break;
                } else {
                    // read in the file path
                    ifstream readfile(filepath.get());
                    // if we can open the file continue
                    if (readfile.is_open()) {
                        // instantiate bucket values
                        string fileline, x_coordinate, y_coordinate;
                        // get the lines from the file
                        while (getline(readfile, fileline)) {
                            // get the lines from the file
                            stringstream line_coordinate(fileline);
                            // get coordinates
                            getline(line_coordinate, x_coordinate, ' ');
                            getline(line_coordinate, y_coordinate, ' ');
                            // convert to number (integer)
                            x = stoi(x_coordinate);
                            y = stoi(y_coordinate);
                            // set the coordinates
                            game->set(x, y);
                        }
                        break;
                    } else {
                        game->message->add("No such file, try again.")->print();
                    }
                }
            }
            // ask to set infinity
            game->setInfinity(false);
        } else if (action.get() == "1") {
            // clean the screen
            Util::clearScreen();
            game->message->add("These are the preset patterns");
            game->message->add("LINE");
            // instantiate Patterns class
            Patterns patterns;
            // loop over the presets
            map<int, string>::iterator preset;
            map<int, string> presets = patterns.getPresets();
            for (preset = presets.begin(); preset != presets.end(); preset++) {
                game->message->add(to_string(preset->first) + ". " + preset->second);
            }
            // add message to allow player to go back
            game->message->add("or 'b' to go back")->print(0);
            // get selected preset
            GetInput activePreset(game->message->ask("Enter your selection: "));
            // load the preset if the correct number was selected
            if ((!activePreset.get().empty() && activePreset.get().find_first_not_of("0123456789") != string::npos) ||
                !patterns.setPreset(stoi(activePreset.get()), game)) {
                game->message->add("No such preset was found, try again.")->print();
                // we try again
                getCoordinates(game);
            }
        } else if (action.get() == "3") {
            // clean the screen
            Util::clearScreen();
            // give info of the coordinates convention
            game->message->add("Coordinates must be given in the following way");
            game->message->add("LINE");
            game->message->add("Each entry must have two numbers separated by a space.");
            game->message->add("The first number is the x axis value, and the second number is the y axis value.");
            game->message->add("So each entry represents a coordinate/cell on the board that is active/alive.");
            game->message->add("The view area of the board has " +
                        to_string(game->getViewSize()) + " x " +
                        to_string(game->getViewSize()) + " = " +
                        to_string(game->getViewArea()) + " cells.")->print();
            // get the coordinates from user manually
            while (true) {
                cout << game->message->ask(
                        "Enter the coordinates of an active/alive cell: ");
                cin >> x >> y;
                // make sure we get numbers
                if (cin.fail()) {
                    // clear to ask the question again
                    cin.clear();
                    cin.ignore();
                    // give the warning
                    game->message->add("Must only be numbers!")->print();
                } else {
                    // set the coordinates
                    game->set(x, y);
                    // check if coordinates are correct
                    game->message->add("Check your entry")->print();
                    // print the set coordinates
                    game->print(3);
                    // final check if the above coordinates are correct and if we must continue adding more
                    game->message->add("To continue you have the following options:");
                    game->message->add("1. Add another cell.");
                    game->message->add("2. Undo that last entry.");
                    // game->message->add("3. Save coordinates to a file and start game->"); TODO
                    game->message->add("3. Stop adding cells.")->print();
                    GetInput optionInput(game->message->ask("Enter the number: "));
                    // ready to start game?
                    if (optionInput.get() == "2") {
                        // unset the last coordinates
                        game->unset(x, y);
                    } else if (optionInput.get() == "3") {
                        // stop adding cells
                        break;
                    }
                }
            }
            game->setInfinity(false);
        } else {
            // quit playing the game
            game->stopPlaying();
        }
    }

    void Util::run(GameOfLife *game) {
        // make sure the game is active
        if (game->isStillPlaying()) {
            // get the coordinates
            Util::getCoordinates(game);
            // make sure the game is active
            if (game->isStillPlaying()) {
                // show the board and the selected coordinates
                game->message->add("LINE");
                game->message->add("These are the coordinates.")->print(0);
                // print the set coordinates
                game->print(0);
                // give notice of infinity treatment
                Util::infinityNote(game);
                // final check if the above coordinates are correct
                game->message->add("LINE");
                GetInput startGame(game->message->ask("Board setup complete. Start the game ? (y/n) "));
                // ready to start game?
                if (startGame.get() == "y" || startGame.get() == "Y") {
                    while (true) {
                        // print the board
                        game->print();
                        // update the board state
                        game->setState();
                        // slow down... ;)
                        usleep(130000);
                        // clean the screen
                        if (game->isActive()) {
                            Util::clearScreen();
                        } else {
                            // show the board and the selected coordinates
                            Util::getCoordinates(game);
                            // if the player quit
                            if (game->isStillPlaying()) {
                                // show the board and the selected coordinates
                                game->message->add("LINE");
                                game->message->add("These are the new coordinates.")->print();
                                // print the set coordinates
                                game->print(0);
                                // give notice of infinity treatment
                                Util::infinityNote(game);
                                // final check if the above coordinates are correct
                                game->message->add("LINE");
                                GetInput startGameAgain(
                                        game->message->ask("Board setup complete. Start the game again ? (y/n) "));
                                if (startGameAgain.get() != "y" && startGameAgain.get() != "Y") {
                                    break;
                                }
                            } else {
                                break;
                            }
                        }
                    }
                }
                // if we are still active
                if (game->isStillPlaying()) {
                    // restart
                    Util::run(game);
                }
            }
        }
    }

    // give notice of infinity treatment
    void Util::infinityNote(GameOfLife *game) {
        if (game->isInfinitySet()) {
            game->message->add("All infinite loops will automatically exit, sit back and enjoy!");
            game->message->add("LINE")->print();
        } else {
            game->message->add("Just a little heads-up, you will need to manually exit the game");
            game->message->add("should it enter an infinite loop (Oscillator).");
            game->message->add("The game will only automatically exit if all visible cells are dead or still.");
            game->message->add("LINE")->print();
        }
    }

    // method to clear the screen
    void Util::clearScreen() {
        // Below Code Taken From This Project https://github.com/MarioTalevski/game-of-life
        // Tested and working on Ubuntu and Cygwin
#if defined(OS_WIN)
        HANDLE hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        DWORD count;
        DWORD cellCount;
        COORD homeCoords = { 0, 0 };

        if (hStdOut == INVALID_HANDLE_VALUE) return;

        /* Get the number of cells in the current buffer */
        GetConsoleScreenBufferInfo( hStdOut, &csbi );
        cellCount = csbi.dwSize.X *csbi.dwSize.Y;

        /* Fill the entire buffer with spaces */
        FillConsoleOutputCharacter(hStdOut, (TCHAR) ' ', cellCount, homeCoords, &count);

        /* Fill the entire buffer with the current colors and attributes */
        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count);

        SetConsoleCursorPosition( hStdOut, homeCoords );

#elif defined(OS_LINUX) || defined(OS_MAC)
        cout << "\033[2J" << "\033[1;1H"; // Clears screen and moves cursor to home pos on POSIX systems
#endif
        // Above Code Taken From This Project https://github.com/MarioTalevski/game-of-life
    }
}
