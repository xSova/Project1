# Clock Program

A simple command-line based clock program that displays time in both 12-hour and 24-hour formats. The program allows users to add hours, minutes, and seconds to the current time, and provides an interface for users to interact with the clock.

## Files and Classes

### main.cpp
- Entry point of the application.
- Contains the main loop that keeps the clock running and handles user commands.

### Clock.h
- Header file containing the `Clock` class definition.
- `Clock` class handles the internal logic and state of the clock.

## Class Descriptions

### Clock Class

- **Public Methods**
    - `initialize()`: Initializes the clock with user input for hours, minutes, and seconds.
    - `updateTime(int timeType)`: Updates the time based on the user command.
    - `clockRun()`: Main method to run the clock, display the time, and handle user inputs.

- **Private Methods**
    - Various utility methods such as `toUpperCase(string str)`, `getTime(int timeType)`, `getMilitaryTime(int hour)`, and others for internal operations and user input handling.

- **Member Variables**
    - `hour`, `minute`, `second`: To store the current time.
    - `isMilitaryTime`, `amTrue`: Boolean flags to handle time format.

- **Static Methods**
    - Static methods for generic operations and user interactions, such as getting time, validating input, and displaying messages.

## How to Run

1. Compile the program:
2. Run the compiled program:

## User Commands

- **1**: Add 1 hour to the current time.
- **2**: Add 1 minute to the current time.
- **3**: Add 1 second to the current time.
- **4**: Exit the program.

## Functionality

- The program initializes by taking user input for the current time.
- Continuously displays the current time in both 12-hour and 24-hour formats.
- Allows the user to increment the time and handles the conversion between different time formats.