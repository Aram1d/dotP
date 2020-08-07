/*  Copyright (C) 2020 W.SUGNIAUX

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */


//This program is designed to convert UTF-8 encoded text to ECMA-94 encoded text so
//that some very old dot-matrix printers can directly write text
///Program for ECMA 94 page code table:

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {

    //Set dmprinter: give the udev file beeing your parallel port
    ofstream dmprinter{"/dev/usb/lp4"};
    string input = argv[1];
    vector<int> output;


    for (std::string::iterator it = input.begin(); it != input.end(); ++it) {

        if (*it == '\xC2') {
            ++it;
            if (it == input.end()) break;
            if (*it >= '\xA0' && *it <= '\xBF') {
                output.push_back(*it);
            }
        }

        if (*it == '\xC3') {
            ++it;
            if (it == input.end()) break;

            if (*it == '\x80') output.push_back('\xC0');
            if (*it == '\x81') output.push_back('\xC1');
            if (*it == '\x82') output.push_back('\xC2');
            if (*it == '\x83') output.push_back('\xC3');
            if (*it == '\x84') output.push_back('\xC4');
            if (*it == '\x85') output.push_back('\xC5');
            if (*it == '\x86') output.push_back('\xC6');
            if (*it == '\x87') output.push_back('\xC7');
            if (*it == '\x88') output.push_back('\xC8');
            if (*it == '\x89') output.push_back('\xC9');
            if (*it == '\x8A') output.push_back('\xCA');
            if (*it == '\x8B') output.push_back('\xCB');
            if (*it == '\x8C') output.push_back('\xCC');
            if (*it == '\x8D') output.push_back('\xCD');
            if (*it == '\x8E') output.push_back('\xCE');
            if (*it == '\x8F') output.push_back('\xCF');

            if (*it == '\x90') output.push_back('\xD0');
            if (*it == '\x91') output.push_back('\xD1');
            if (*it == '\x92') output.push_back('\xD2');
            if (*it == '\x93') output.push_back('\xD3');
            if (*it == '\x94') output.push_back('\xD4');
            if (*it == '\x95') output.push_back('\xD5');
            if (*it == '\x96') output.push_back('\xD6');
            if (*it == '\x97') output.push_back('\xD7');
            if (*it == '\x98') output.push_back('\xD8');
            if (*it == '\x99') output.push_back('\xD9');
            if (*it == '\x9A') output.push_back('\xDA');
            if (*it == '\x9B') output.push_back('\xDB');
            if (*it == '\x9C') output.push_back('\xDC');
            if (*it == '\x9D') output.push_back('\xDD');
            if (*it == '\x9E') output.push_back('\xDE');
            if (*it == '\x9F') output.push_back('\xDF');

            if (*it == '\xA0') output.push_back('\xE0');
            if (*it == '\xA1') output.push_back('\xE1');
            if (*it == '\xA2') output.push_back('\xE2');
            if (*it == '\xA3') output.push_back('\xE3');
            if (*it == '\xA4') output.push_back('\xE4');
            if (*it == '\xA5') output.push_back('\xE5');
            if (*it == '\xA6') output.push_back('\xE6');
            if (*it == '\xA7') output.push_back('\xE7');
            if (*it == '\xA8') output.push_back('\xE8');
            if (*it == '\xA9') output.push_back('\xE9');
            if (*it == '\xAA') output.push_back('\xEA');
            if (*it == '\xAB') output.push_back('\xEB');
            if (*it == '\xAC') output.push_back('\xEC');
            if (*it == '\xAD') output.push_back('\xED');
            if (*it == '\xAE') output.push_back('\xEE');
            if (*it == '\xAF') output.push_back('\xEF');

            if (*it == '\xB0') output.push_back('\xF0');
            if (*it == '\xB1') output.push_back('\xF1');
            if (*it == '\xB2') output.push_back('\xF2');
            if (*it == '\xB3') output.push_back('\xF3');
            if (*it == '\xB4') output.push_back('\xF4');
            if (*it == '\xB5') output.push_back('\xF5');
            if (*it == '\xB6') output.push_back('\xF6');
            if (*it == '\xB7') output.push_back('\xF7');
            if (*it == '\xB8') output.push_back('\xF8');
            if (*it == '\xB9') output.push_back('\xF9');
            if (*it == '\xBA') output.push_back('\xFA');
            if (*it == '\xBB') output.push_back('\xFB');
            if (*it == '\xBC') output.push_back('\xFC');
            if (*it == '\xBD') output.push_back('\xFD');
            if (*it == '\xBE') output.push_back('\xFE');
            if (*it == '\xBF') output.push_back('\xFF');

        } else { //if char is in ASCII table
            output.push_back(*it);
        }
    }
    output.push_back('\x0A');

    //Finally send the content of output vector to the printer
    for (int i = 0; i < output.size(); i++) {
        dmprinter << static_cast<char>(output.at(i));
    }
    return 0;
}






