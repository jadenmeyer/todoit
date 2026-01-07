#include <fstream>
#include <iostream>

#include "../structures/prio_queue.hpp"

void printToFile(prio_queue& queue) {
  std::fstream File("tasks.txt",
                    std::fstream::in | std::fstream::out | std::fstream::trunc);
  if (File.is_open()) {
    while (!queue.is_empty()) {
      tasks task;
      task = queue.extract_max();
      File << task.name << " " << task.priority << std::endl;
    }
    std::cout << "changes written to file \"tasks.txt\"" << std::endl;
    File.close();
  } else {
    std::cerr << "unable to create/edit a file" << std::endl;
    return;
  }
}

void readFile(prio_queue& queue) {
  std::fstream File("tasks.txt", std::fstream::in);
  if (File.is_open()) {
    tasks inTask;
    while (File >> inTask.name >> inTask.priority) {
      queue.insert(inTask);
    }
    File.close();
  } else {
    std::cerr << "failed to open file" << std::endl;
  }
}

bool fileExists() {
  std::fstream File("tasks.txt", std::fstream::in);
  if (File.is_open()) {
    File.close();
    return true;
  } else
    return false;
}
