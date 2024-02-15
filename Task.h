#pragma once
#include <string>

class Task {
    
    private:
    std::string description;
    bool completed;
    time_t dueDate; //Due date for the task

    public:
    Task(const std::string& description, time_t dueDate = 0);
    std::string getDescription() const;
    bool isCompleted() const;
    void markComplete();
    time_t getDueDate() const; //getter method for due date
};