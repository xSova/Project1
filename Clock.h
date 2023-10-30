//
// Created by Bryce on 10/29/2023.
//

#ifndef PROJECT1_CLOCK_H
#define PROJECT1_CLOCK_H

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>

using namespace std;

class Clock {

public:

    // Member variable declarations
    int hour = 0;
    int minute = 0;
    int second = 0;
    int inputCmd = 0; // Default input command is 0.
    bool isMilitaryTime = false;
    bool amTrue = false;

    // Static function to convert a string to uppercase.
    static string toUpperCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        return str;
    };

    // Static function to get time input (hour, minute, second) from the user with validation.
    static int getTime(int timeType) {
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
    };

    // Function to get military time input from user with validation.
    static bool getMilitaryTime(int hour) {
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
    };

    // Function to get AM/PM input from user with validation.
    static bool getAMorPM() {
        string tempStr;

        while(true) { //Keep asking for input until valid input is gathered.
            cout << "AM or PM?";
            cin >> tempStr;

            if (toUpperCase(tempStr) == "AM") return true;
            if (toUpperCase(tempStr) == "PM") return false;

            cout << "Invalid input. Please enter 'AM' or 'PM'." << endl;
            cin.clear(); //Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discard incorrect input.
        }
    };

    // Function to process and set the hour based on user input and chosen time format.
    void processInputHour(int timeInput) {
        bool isAM = true;

        // If hour is greater than 12, assume it is military time.
        if (timeInput >= 12) {
            isMilitaryTime = true;
        }
        else {
            isMilitaryTime = getMilitaryTime(timeInput);
        }

        if (!isMilitaryTime) {
            amTrue = getAMorPM();

            if (!amTrue && hour < 12) { //PM and hour isn't 12
                hour += 12;
            } else if (amTrue && hour == 12) { //12 AM
                hour = 0;
            }
        } // If getAMorPM returns true, the time period is AM.
    };

    // Function to initialize the clock with user inputs.
    void initialize() { // Initial command to get initial times.
        hour = getTime(1);
        processInputHour(hour);
        minute = getTime(2);
        second = getTime(3);
        cout << endl;
    };

    // Function to update the time based on user commands.
    void updateTime(int timeType) {
        switch (timeType) {
            case 1:
                hour = (hour + 1) % 24;
                break;
            case 2:
                minute++;
                if (minute == 60) {
                    minute = 0;
                    updateTime(1);
                }
                break;
            case 3:
                second++;
                if (second == 60) {
                    second = 0;
                    updateTime(2);
                }
                break;
        }
    };

    // Static function to display available commands to the user.
    static void displayCommands() {
        cout << "*********************************************************" << endl;
        cout << "*                       Commands:                       *" << endl;
        cout << "*          1 - Add 1 hour     2 - Add 1 minute          *" << endl;
        cout << "*          3 - Add 1 second   4 - Exit                  *" << endl;
        cout << "*********************************************************" << endl;
    };

    // Static function to display top and bottom of clock displays to the user.
    static void printSeparator() {
        cout << "***************************" << "   " << "***************************" << endl;
    };

    // Static function to display the headers of the clock displays to the user for both 12-hour and 24-hour format.
    static void printClockTitle(string title) {
        int padding = (27 - title.length()) / 2; // Center padding
        cout << "*" << setw(padding+title.length()) << right << title
             << setw(26-padding-title.length()) << right << "*" ;
    }

    // Function to be called in displayTime() to print the time calculated in displayTime()
    void printTime(int hour, int minute, int second, string period = "") {
        stringstream timeStream;
        timeStream << setfill('0')
                   << setw(2) << hour << ":" << setw(2) << minute << ":"
                   << setw(2) << second;
        if (!period.empty()) timeStream << " " << period;

        string timeStr = timeStream.str();
        int padding = (27 - timeStr.length()) / 2; // Center padding
        cout << "*" << setw(padding+timeStr.length()) << right << timeStr
             << setw(26-padding-timeStr.length()) << right << "*";
    }

    // Function to display the current time in 12-hour and 24-hour format
    void displayTime() {
        int displayHour24 = (hour == 12 && amTrue && !isMilitaryTime) ? 0 : hour; // If the time is 12am it should make 24-hour time hour = 0
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
    };

    // Function to run the clock and handle user commands.
    bool clockRun() {

        while (inputCmd != 4) {
          displayTime(); // Display the current time.
          cin >> inputCmd; // Get the user command.

          if(cin.fail()) { // Validate the user input.
              cin.clear(); // Clear the error flag.
              cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the incorrect input.
              cout << "Invalid command. Please enter a number between 1 and 4." << endl;
              continue; // Ask for the user command again.
          }

          // Execute the user command if valid.
          if (inputCmd >= 1 && inputCmd <= 3) {
              updateTime(inputCmd);
          }
        }
        return false; // Stop running the clock when the user enters 4.
    };
};


#endif //PROJECT1_CLOCK_H
