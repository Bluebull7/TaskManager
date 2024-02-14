#pragma once
#include <string>

class Task {
    
    private:
    std::string description;
    bool completed;

    public:
    Task(const std::string& description);
    std::string getDescription() const;
    bool isCompleted() const;
    void markComplete();
};