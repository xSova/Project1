//
// Created by Bryce on 10/24/2023.
//

#ifndef PROJECT1_CLOCK_H
#define PROJECT1_CLOCK_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Clock {
public:
    //default times
    int hour = 0;
    int minute = 0;
    int second = 0;
    //default input = 0
    int inputCmd = 0;
    //initial command to get initial times
    void initialize() {
        //Prompt user for time
        cout << "What is the hour?" << endl;
        cin >> this->hour;
        cout << "What is the minute?" << endl;
        cin >> this->minute;
        cout << "What is the second?" << endl;
        cin >> this->second;
    };

    void displayTime() const {
        //FIXME: add logic for displaying the time width 26char

        cout << "***************************" << "   " << "***************************" << endl;
        cout << "*     " << "12-Hour clock" << "       *" << "   " << "*     " << "24-Hour clock" << "       *" << endl;
        cout << "*     " << " " << "XX" << ":" << "XX" << ":" << "XX" << " XM " << "       *" << "   " << "*     " << "   XX:XX:XX  " << "       *" << endl;
        cout << "***************************" << "   " << "***************************" << endl;
    };
    /*FIXME: create a function that prints a 2 character time that is formatted correctly
     * add in 12 and 24 hour variables for hour minute second
     * if you use one or the other at initialization, the times are based on whichever was input first
     * add in logic for am and pm that is based on the calculated 24 hour time
     * add in logic for if hour increment makes the hour > 12 for 12 hour and > 23 for 24 hour
     * add in logic for if minute increment makes the minute > 59
     * add in logic for if minute increment makes the seconds > 59
     * add in the output functions for time formatting
     * */
    static void displayCommands() {
        cout << "*********************************************************" << endl;
        cout << "*                       Commands:                       *" << endl;
        cout << "*          1 - Add 1 hour     2 - Add 1 minute          *" << endl;
        cout << "*          3 - Add 1 second   4 - Exit                  *" << endl;
        cout << "*********************************************************" << endl;
    };
    /*int hourProcessInit(int hour){ //outputs 2 character long string
        string outputHour = "";
        if (hour >= 0 && hour <= 23) { //check if initial hour input is valid
            cout << setw(2) << setfill('0') << hour;
        }
    };
    void formatHour(int hour, int caller) {
        if(hour >= 0 && hour <= 23) { // Check if the input is a valid hour
            cout << "Formatted hour: ";
            cout << setw(2) << setfill('0') << hour; // This will ensure the hour is displayed with two digits
            cout << endl;
        } else {
            cout << "Invalid hour input." << endl;
        }
    };*/
    void processCommand(int cmd) {
        switch (cmd) {
            case 1:
                hour++;
                break;
            case 2:
                minute++;
                break;
            case 3:
                second++;
                break;
            case 4:
                break;
            default:
                cout << "Invalid command." << endl;
                this->inputCmd = 0;

        };
    };

    bool clockRun() {

        while (inputCmd != 4) {
          this->displayTime();
          this->displayCommands();
          cin >> inputCmd;
          this->processCommand(inputCmd);
        };
        return false;
    };
};


#endif //PROJECT1_CLOCK_H
