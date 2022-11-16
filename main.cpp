#include "TaskSelector.h"
#include "Printer.h"
#include "Util/Input.h"

int main()
{
    TaskSelector taskSelector = TaskSelector();
    const std::vector<std::string> tasks = taskSelector.getTasks();
    std::string answer;
    while (true) {
        std::cout << "List of tasks: ";
        Printer::printVector(tasks);
        std::cout << "Choose a task:";
        answer = Input::loopQuestion<TaskSelector>(&TaskSelector::hasTask,taskSelector,"0");
        if (answer == "__EXIT__")
            break;
        taskSelector.launch(answer);
    }
    return 0;
}