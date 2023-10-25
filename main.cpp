#include <iostream>
#include "Clock.h"

using namespace std;

int main() {
    bool running = true;
    Clock clockDefault = *new Clock;
    clockDefault.initialize();
    while (running) {
        cout << "Hour: " << clockDefault.hour << endl;
        cout << "Minute: " << clockDefault.minute << endl;
        cout << "Second: " << clockDefault.second << endl;
        running = clockDefault.clockRun();
    };
    return 0;
}
