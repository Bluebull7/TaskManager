#include "Task.h"

Task::Task(const std::string& description) : description(description), completed(false) {}

std::string Task::getDescription() const {
    return description;
}

bool Task::isCompleted() const {
    return completed;
}

void Task::markComplete() {
    completed = true;
}