#include "TaskManager.h"
#include <iostream>

void TaskManager::addTask(const std::string& description) {
    Task newTask(description);
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
        if (tasks[i].isCompleted()) {
            std::cout << " (Completed)";
        }
        std::cout << std::endl;
    }
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