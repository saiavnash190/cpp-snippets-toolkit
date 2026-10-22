#pragma once
#include <chrono>
#include <iostream>
#include <string>

class ExecutionTimer {
public:
    ExecutionTimer(std::string task_name = "Task")
        : name(std::move(task_name)), start(std::chrono::high_resolution_clock::now()) {}

    ~ExecutionTimer() {
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "[" << name << "] executed in " << duration.count() << " microseconds\n";
    }

private:
    std::string name;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
};
