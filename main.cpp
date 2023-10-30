#include <iostream>
#include "Clock.h"

using namespace std;

int main() {
    bool running = true; // This keeps the loop running until Clock.clockRun() returns false, breaking the loop.
    Clock clockDefault;
    clockDefault.initialize(); // Initializing the clock with user input.
    while (running) { // Main loop for running the clock.
        running = clockDefault.clockRun(); // Runs the clock and updates the running status.
    }
    return 0;
}
