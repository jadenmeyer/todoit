#include <iostream>
#include <string>

#include "structures/task_container.hpp"

struct information {
  std::string name;
  int priority;
};

int main(int argc, char* argv[]) {
  // struct information info;

  task_container<struct information> big_test;
  for (int i = 0; i < 100; i++) {
    struct information info;
    info.name = "test";
    info.priority = 1;
    big_test.add(info);
  }

  for (int i = 0; i < 100; i++) {
    std::cout << big_test[i].name << " : " << big_test[i].priority << std::endl;
  }

  return 0;
}
