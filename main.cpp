#include <iostream>
#include "TaskSelector.h"

int main() {
    TaskSelector taskSelector = TaskSelector();
    const std::vector<std::string> tasks = taskSelector.getTasks();
    const int size = tasks.size();
    for (int i = 0; i < size-1; i++)
    {
        std::cout << tasks[i] + ", ";
    }
    std::cout << tasks[size-1] << "\n";
    std::string answer = "";
    while (true) {
        while (!taskSelector.hasTask(answer)) {
            std::cin >> answer;
            if (answer == "0") goto EXIT;
        }
        taskSelector.launch(answer);
        answer = "";
    }
    EXIT:
    return 0;
}
