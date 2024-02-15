#include "TaskManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>

void TaskManager::addTask(const std::string& description, time_t dueDate) {
    Task newTask(description, dueDate);
    tasks.push_back(newTask);
}

void TaskManager::markTaskComplete(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].markComplete();
    }
}

void TaskManager::listTasks() const {
    for (size_t i=0; i < tasks.size(); i++) {
        std::cout << "[" << (i+1) << "] " << tasks[i].getDescription();
        if (tasks[i].getDueDate() != 0) {
            std::cout << " (Due: " << std::put_time(std::localtime(&tasks[i].getDueDate()), "%c") << ")";
        }
        
        if (tasks[i].isCompleted()) {
            std::cout << " (Completed)";
        }
        std::cout << std::endl;
    }
}

void TaskManager::saveTasksToFile(const std::string& filename) const {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file for writing.\n";
        return;
    }

    outputFile.close();
}

void TaskManager::loadTasksFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if(!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file for reading.\n";
        return;
    }

    tasks.clear(); // clear existing tasks before loading from file

    std::string line;
    while(std::getline(inputFile, line)) {
        size_t commaPos1 = line.find(',');
        size_t commaPos2 = line.find(',', commaPos1 + 1);

        std::string description = line.substr(0, commaPos1);
        time_t dueDate = std::stol(line.substr(commaPos1 + 1, commaPos2 - commaPos1 - 1));
        bool completed = (line.substr(commaPos2 + 1) == "1");

        Task loadedTask(description, dueDate);
        if (completed) {
            loadedTask.markComplete();
        }

        tasks.push_back(loadedTask);

    }

    inputFile.close();
}

int main() {
    TaskManager taskManager;

    //Adding Tasks
    taskManager.addTask("Complete Project", time(0));
    taskManager.addTask("Read Book", time(0));
    taskManager.addTask("Exercise", time(0));

    //Marking tasks as complete
    taskManager.markTaskComplete(1);

    //Listing Tasks
    taskManager.listTasks();

    //Saving tasks 
    taskManager.saveTasksToFile("tasks.txt");

    // Loading tasks from a file
    taskManager.loadTasksFromFile("tasks.txt");

    // Listing tasks after loading 
    taskManager.listTasks();

    return 0;
}