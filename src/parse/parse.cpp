#include <fstream>
#include <iostream>

#include "../structures/prio_queue.hpp"

void printToFile(prio_queue& queue) {
  std::cout << queue.get_size() << std::endl;
  std::fstream File("test.txt",
                    std::fstream::in | std::fstream::out | std::fstream::trunc);
  if (File.is_open()) {
    while (!queue.is_empty()) {
      tasks task;
      task = queue.extract_max();
      std::cout << task.name << " " << task.priority << std::endl;
      File << task.name << " " << task.priority << std::endl;
    }
    File.close();
  } else {
    std::cerr << "unable to create a file" << std::endl;
    return;
  }
}

void readFile(prio_queue& queue) {
  std::fstream File("test.txt",
                    std::fstream::in);  // trunc for creation
  if (File.is_open()) {
    tasks inTask;
    while (File >> inTask.name >> inTask.priority) {
      // std::cout << inTask.name << " " << inTask.priority << std::endl;
      queue.insert(inTask);
    }
    File.close();
  } else {
    std::cerr << "failed to open file" << std::endl;
  }
}
