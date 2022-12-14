#pragma once
#include <string>
#include <vector>

class TaskSelector
{
public:
    static const std::vector<std::vector<std::string>> TASKS;
    std::vector<std::string> formattedTasks;

    TaskSelector();

    void launch(std::string& task);
    std::vector<std::string> getTasks();
    bool hasTask(const std::string& task);
private:
    int createTask(std::string &task);
};
