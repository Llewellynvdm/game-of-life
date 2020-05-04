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

#ifndef GOL_MESSAGE_H
#define GOL_MESSAGE_H

// internal classes
#include "color.h"
// libraries
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

namespace GOL {
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     *  I am trying out namespace just to see how it works :) any input would be great!
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    // class to manage all messages
    class Message {
    private:
        // message color
        string color = COLOR_GREEN;
        string color_reset = COLOR_RESET;
        // the message string
        string message;
        // line max length
        int max_length = 95;
        // line character
        string spacer_line = "-";
        // string ending
        string end = "#";

        // prep string
        string prepLine(string &str, string &padding);

    public:
        // space character
        string spacer = " ";
        // string beginning
        string begin = "#";

        // constructor
        Message(string lines = "") : message{lines} {
            cout << color;
        }

        // destructor
        ~Message() {
            cout << color_reset;
        }

        // print method
        void print(int addNewLine = 1);

        // get message
        string get(int addNewLine = 1);

        // add line method
        Message *add(string line, string newline = "\n");

        // to model a question for the get input class
        string ask(string question);

        // add padding around string
        string addPadding(string str, int length, string &padding);

        string addPadding(int length, string str, string &padding);
    };
}

#endif //GOL_MESSAGE_H
