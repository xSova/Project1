//
// Created by Bryce on 11/4/2023.
//

#ifndef PROJECT1_CLOCKINTERFACE_H
#define PROJECT1_CLOCKINTERFACE_H

#include <string>

using namespace std;

class ClockInterface {
public:
    static void displayCommands(); // Display available commands to the user.
    static void printSeparator(); // Display top and bottom of clock displays.
    static void printClockTitle(string title); // Display the headers of the clock displays.
    static int getTime(int timeType); // Get time input from the user with validation.
    static bool getMilitaryTime(); // Get military time input from user.
    static bool getAMorPM(); // Get AM/PM input from user.
    static void
    displayTime(int hour, int minute, int second, bool isMilitaryTime, bool amTrue); // Display the current time.
    static void printTime(int hour, int minute, int second, string period = ""); // Helper function to print the time.
};

#endif //PROJECT1_CLOCKINTERFACE_H


