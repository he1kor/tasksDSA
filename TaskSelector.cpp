#include "TaskSelector.h"

#include <stdexcept>
#include <iostream>
#include <limits>

#include "1/1/Main.h"
#include "1/2/Main.h"

/**
 * Launches selected task object
 */

const std::vector<std::vector<std::string>> TaskSelector::TASKS =
        {
                {"1","2"}
        };

TaskSelector::TaskSelector()
{
    for (int taskNumber = 0; taskNumber < TASKS.capacity(); taskNumber++)
    {
        for (int subTaskNumber = 0; subTaskNumber < TASKS[taskNumber].capacity(); subTaskNumber++)
        {
            formattedTasks.push_back(std::to_string(taskNumber+1) + "." + TASKS[taskNumber][subTaskNumber]);
        }
    }
}

void TaskSelector::launch(std::string& task)
{
    if (task == ""){
        throw std::invalid_argument("Provided task is empty");
    }
    if (!hasTask(task))
        throw std::invalid_argument("TaskSelector hasn't task " + task);

    std::cout << "\n" << std::string(40,'-');
    std::cout << "\n" << "The task " << task << " is starting...";
    std::cout << "\n" << std::string(40,'-') << "\n";

    int finishing_status;
    try {
        finishing_status = createTask(task);
    }
    catch (std::exception&){
        finishing_status = 1;
    }
    if (finishing_status == 0){
        std::cout << "\n" << std::string(40,'-');
        std::cout << "\n" << "The task finished successfully";
        std::cout << "\n" << std::string(40,'-') << "\n";
    } else {
        std::cout << "\n" << std::string(40,'-');
        std::cout << "\n" << "The task finished with an error " << finishing_status;
        std::cout << "\n" << std::string(40,'-') << "\n";
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
int TaskSelector::createTask(std::string& task){
    if (task == formattedTasks[0]) return task1_1::Main().run();
    if (task == formattedTasks[1]) return task1_2::Main().run();
    throw std::runtime_error("something went wrong");
}

bool TaskSelector::hasTask(const std::string& task)
{
    return std::any_of(formattedTasks.begin(),formattedTasks.end(),
                       [task](const std::string& possibleTask){return task == possibleTask;});
}

std::vector<std::string> TaskSelector::getTasks()
{
    return formattedTasks;
}
