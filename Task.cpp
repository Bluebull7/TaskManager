#include "Task.h"

Task::Task(const std::string& description, time_t dueDate)
: description(description), completed(false), dueDate(dueDate) {}

std::string Task::getDescription() const {
    return description;
}

bool Task::isCompleted() const {
    return completed;
}

void Task::markComplete() {
    completed = true;
}

