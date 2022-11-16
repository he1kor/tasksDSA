#include "TaskSelector.h"
#include "Printer.h"
#include "Util/Input.h"

int main()
{
    TaskSelector taskSelector = TaskSelector();
    const std::vector<std::string> tasks = taskSelector.getTasks();
    Printer::printVector(tasks);
    std::string answer;
    while (true) {
        answer = Input::loopQuestion<TaskSelector>("Choose program: ",&TaskSelector::hasTask,taskSelector,"0");
        if (answer == "__EXIT__") break;
        taskSelector.launch(answer);
    }
    return 0;
}
