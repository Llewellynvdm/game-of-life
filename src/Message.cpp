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
#include "Message.h"
// libraries
#include <iomanip>
#include <string>

namespace GOL {
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     *  I am trying out namespace just to see how it works :) any input would be great!
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    // print to terminal the message
    void Message::print(int addNewLine) {
        // stay in the terminal color
        cout << color;
        // only print the message
        if (addNewLine == 1) {
            cout << message << endl;
        } else {
            cout << message;
        }
        // empty the message value
        message = "";
    }

    // get the message
    string Message::get(int addNewLine) {
        // get message
        string tmp = message;
        // empty the message value
        message = "";
        // only print the message
        if (addNewLine == 1) {
            return tmp + "\n";
        } else {
            return tmp;
        }
    }

    // add a line to the message
    Message *Message::add(string line, string newline) {
        if ("LINE" == line) {
            // add a line
            line = "";
            message += this->addPadding(line, max_length, spacer_line) + newline;
        } else {
            // store the string
            message += this->prepLine(line, spacer) + newline;
        }
        return this;
    }

    // prepare a string before adding
    string Message::prepLine(string &str, string &padding) {
        // add padding
        return this->addPadding(3, str, padding);
    }

    // to model a question for the get input class
    string Message::ask(string question) {
        // stay in the terminal color
        cout << color;
        return addPadding(3, question, spacer);
    }

    // add padding in front of string
    string Message::addPadding(int length, string str, string &padding) {
        for (int i = 0; i < length; i++) {
            str = padding + str;
        }
        return str;
    }

    // add padding behind string
    string Message::addPadding(string str, int length, string &padding) {
        // get the string length
        int string_length = str.length();
        for (int i = string_length; i < length; i++) {
            str += padding;
        }
        return str;
    }
}

