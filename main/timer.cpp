#include <iostream>
#include <chrono>
#include <thread>

void timerDelay(int tempoEmMs) {
    std::this_thread::sleep_for(std::chrono::milliseconds(tempoEmMs));
}
