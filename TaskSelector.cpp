#include "TaskSelector.h"

#include <stdexcept>

#include "1/Main.h"
#include "2/Main.h"

/**
 * Launches selected task object
 */

const std::vector<std::vector<std::string>> TaskSelector::TASKS =
        {
                {"1","2","3"},
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

int TaskSelector::launch(std::string& task)
{
    if (!hasTask(task))
        throw std::invalid_argument("TaskSelector hasn't task " + task);

    if (task == formattedTasks[0]) return task1::Main().run();
    if (task == formattedTasks[1]) return task2::Main().run();
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
