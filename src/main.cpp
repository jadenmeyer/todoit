#include <curses.h>

#include <iostream>

#include "parse/parse.h"
#include "structures/prio_queue.hpp"
// not used currently proboably wont #include "structures/task_container.hpp"

int main(int argc, char* argv[]) {
  prio_queue queue;
  if (fileExists()) {
    readFile(queue);
  }
  while (true) {
    struct tasks info;
    std::cout << "What is your Task? ";
    std::cin >> info.name;
    if (info.name == "quitapp") break;
    std::cout << std::endl;
    std::cout << "What is the Task's priority? ";
    while (!(std::cin >> info.priority)) {
      std::cout << "Invalid input. Please enter a number for priority: ";
      std::cin.clear();  // error flags flushed
      std::cin.ignore(10000, '\n');
    }
    queue.insert(info);
  }
  printToFile(queue);
  return 0;
}
