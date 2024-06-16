#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <thread>
#include <functional>
#include <atomic>

class Timer {
public:
    Timer() : running(false) {}

    ~Timer() {
        stop();
    }

    void start(std::chrono::milliseconds interval, std::function<void()> callback) {
        if (running) {
            stop();
        }
        running = true;
        timer_thread = std::thread([this, interval, callback]() {
            while (running) {
                auto start = std::chrono::high_resolution_clock::now();
                callback();
                auto end = std::chrono::high_resolution_clock::now();
                std::this_thread::sleep_for(interval - std::chrono::duration_cast<std::chrono::milliseconds>(end - start));
            }
        });
    }

    void stop() {
        running = false;
        if (timer_thread.joinable()) {
            timer_thread.join();
        }
    }

private:
    std::atomic<bool> running;
    std::thread timer_thread;
};

#endif
