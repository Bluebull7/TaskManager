#pragma once
#include <vector>
#include "Task.h"

class TaskManager {
    private:
        std::vector<Task> tasks;

    public:
        void addTask(const std::string& description, time_t dueDate = 0);
        void markTaskComplete(int index);
        void listTasks() const;
        void saveTasksToFile(const std::string& filename) const;
        void loadTasksFromFile(const std::string& filename);
};