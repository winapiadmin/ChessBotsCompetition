#pragma once
#include <chrono>
class Timer {
    int wtime;
    int btime;
    int winc;
    int binc;
    std::chrono::time_point<std::chrono::steady_clock> start_time;

    int elapsed()
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(steady_clock::now() - start_time).count();
    }
}
