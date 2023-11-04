//
// Created by Bryce on 11/4/2023.
//

#include "ClockInterface.h"

#ifndef PROJECT1_CLOCK_H
#define PROJECT1_CLOCK_H

using namespace std;

class Clock : public ClockInterface {
public:
    Clock(); // Constructor
    ~Clock(); // Destructor

    void initialize(); // Function to initialize the clock with user inputs.
    void updateTime(int timeType); // Function to update the time based on user commands.
    bool clockRun(); // Function to run the clock and handle user commands.

private:
    int hour;
    int minute;
    int second;
    int inputCmd;
    bool isMilitaryTime;
    bool amTrue;

    void
    processInputHour(int timeInput); // Function to process and set the hour based on user input and chosen time format.

#endif //PROJECT1_CLOCK_H

};