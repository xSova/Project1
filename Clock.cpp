//
// Created by Bryce on 10/24/2023.
//

#include <iostream>
#include <limits>
#include "Clock.h"

using namespace std;

// Function to initialize the clock with user inputs.
void Clock::initialize() { // Initial command to get initial times.
    hour = getTime(1);
    processInputHour(hour);
    minute = getTime(2);
    second = getTime(3);
    cout << endl;
}

// Function to run the clock and handle user commands.
bool Clock::clockRun() {

    while (inputCmd != 4) {
        displayTime(hour, minute, second, isMilitaryTime, amTrue); // Display the current time.
        cin >> inputCmd; // Get the user command.

        if (cin.fail() || inputCmd < 1 || inputCmd > 4) { // Validate the user input.
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
}


// Function to process and set the hour based on user input and chosen time format.
void Clock::processInputHour(int timeInput) {

    // If hour is greater than 12, assume it is military time.
    if (timeInput > 12) {
        isMilitaryTime = true;
    } else {
        isMilitaryTime = getMilitaryTime();
    }

    if (!isMilitaryTime) {
        amTrue = getAMorPM();

        if (!amTrue && hour < 12) { //PM and hour isn't 12
            hour += 12;
        } else if (amTrue && hour == 12) { //12 AM
            hour = 0;
        }
    } // If getAMorPM returns true, the time period is AM.
}

// Function to update the time based on user commands.
void Clock::updateTime(int timeType) {
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
}