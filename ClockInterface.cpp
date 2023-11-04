//
// Created by Bryce on 11/4/2023.
//

#include "ClockInterface.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>

using namespace std;

// Static function to convert a string to uppercase.
static string toUpperCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

// Function to display available commands to the user.
void ClockInterface::displayCommands() {
    cout << "*********************************************************" << endl;
    cout << "*                       Commands:                       *" << endl;
    cout << "*          1 - Add 1 hour     2 - Add 1 minute          *" << endl;
    cout << "*          3 - Add 1 second   4 - Exit                  *" << endl;
    cout << "*********************************************************" << endl;
}

// Static function to display top and bottom of clock displays to the user.
void ClockInterface::printSeparator() {
    cout << "***************************" << "   " << "***************************" << endl;
}

// Static function to display the headers of the clock displays to the user for both 12-hour and 24-hour format.
void ClockInterface::printClockTitle(string title) {
    int padding;
    padding = (27 - title.length()) / 2; // Center padding
    cout << "*" << setw(padding + title.length()) << right << title
         << setw(26 - padding - title.length()) << right << "*";
}

// Static function to get time input (hour, minute, second) from the user with validation.
int ClockInterface::getTime(int timeType) {
    int outputToBeChecked;
    string timeUnit;
    int maxLimit; //Maximum allowable value for hour, minute, or second.

    switch (timeType) {
        case 1://hour
            timeUnit = "hour";
            maxLimit = 23; // Maximum value for hours.
            break;
        case 2://min
            timeUnit = "minute";
            maxLimit = 59; // Maximum value for minutes.
            break;
        case 3://second
            timeUnit = "second";
            maxLimit = 59; // Maximum value for seconds.
            break;
        default:
            return -1; // Return -1 or throw an error if timeType is invalid.
    }

    do {
        cout << "Enter the " << timeUnit << ":";
        while (!(cin >> outputToBeChecked)) { // Check if the input is a number.
            cin.clear(); // Clear the error flag.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the incorrect input.
            cout << "Invalid input; please re-enter." << endl;
            cout << "Enter the " << timeUnit << ":";
        }
        if (outputToBeChecked < 0 || outputToBeChecked > maxLimit) { // Validate the input range.
            cout << "Invalid " << timeUnit << ". Please enter a value between 0 and " << maxLimit << ".\n";
        }
    } while (outputToBeChecked < 0 || outputToBeChecked > maxLimit); // Repeat until a valid input is received.

    return outputToBeChecked;
}

// Function to get military time input from user with validation.
bool ClockInterface::getMilitaryTime() {
    string tempStr;

    while (true) { //Keep asking until a valid input is received.
        cout << "Is this military time (24 hour)? <y/n>";
        cin >> tempStr;
        if ((toUpperCase(tempStr) == "Y") || (toUpperCase(tempStr) == "N")) {
            return (toUpperCase(tempStr) == "Y");
        } else {
            cout << "Invalid input. Please enter y or n." << endl;
            cin.clear();//clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignore incorrect input
        }
    }
}

// Function to get AM/PM input from user with validation.
bool ClockInterface::getAMorPM() {
    string tempStr;

    while (true) { //Keep asking for input until valid input is gathered.
        cout << "AM or PM?";
        cin >> tempStr;

        if (toUpperCase(tempStr) == "AM") return true;
        if (toUpperCase(tempStr) == "PM") return false;

        cout << "Invalid input. Please enter 'AM' or 'PM'." << endl;
        cin.clear(); //Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discard incorrect input.
    }
}

// Function to display the current time in 12-hour and 24-hour format
void ClockInterface::displayTime(int hour, int minute, int second, bool isMilitaryTime, bool amTrue) {
    int displayHour24 = (hour == 12 && amTrue && !isMilitaryTime) ? 0
                                                                  : hour; // If the time is 12am it should make 24-hour time hour = 0
    int displayMinute24 = minute;
    int displaySecond24 = second;

    string period = "AM";
    int displayHour12 = hour;

    if (hour == 12 || hour == 0) {
        displayHour12 = 12;
    } else if (hour > 12) {
        displayHour12 = hour - 12;
    }

    if (hour >= 12) {
        period = "PM";
    }

    printSeparator();
    printClockTitle("12-Hour Clock");
    cout << "   ";
    printClockTitle("24-Hour Clock");
    cout << endl;

    printTime(displayHour12, minute, second, period);
    cout << "   ";
    printTime(displayHour24, displayMinute24, displaySecond24);
    cout << endl;

    printSeparator();
    displayCommands();
}

// Function to be called in displayTime() to print the time calculated in displayTime()
void ClockInterface::printTime(int hour, int minute, int second, string period) {
    stringstream timeStream;
    timeStream << setfill('0')
               << setw(2) << hour << ":" << setw(2) << minute << ":"
               << setw(2) << second;
    if (!period.empty()) timeStream << " " << period;

    string timeStr = timeStream.str();
    int padding = (27 - timeStr.length()) / 2; // Center padding
    cout << "*" << setw(padding + timeStr.length()) << right << timeStr
         << setw(26 - padding - timeStr.length()) << right << "*";
}