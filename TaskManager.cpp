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

    while (true) {
        std::cout << "1. Add Task\n";
        std::cout << "2. Mark Task as Complete\n";
        std::cout << "3. List Tasks \n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        
        case 1: {
            std:: string description;
            std::cout << "Enter task description: ";
            std::cin.ignore();
            std::getline(std::cin, description);
            taskManager.addTask(description);
            
            break;
        }

        case 2: {
            int index;
            std::cout << "Enter task index to mark as complete: ";
            std::cin >> index;
            taskManager.markTaskComplete(index - 1);
            break;
        }

        case 3: {
            taskManager.listTasks();
            break;
        }
        case 0: {
            return 0;
        
        default:
            std::cout <<"Invalid choice... Please try again..\n";
        }
    }
}    
    return 0;
}