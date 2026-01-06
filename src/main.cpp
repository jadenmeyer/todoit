#include <iostream>
#include <string>

#include "parse/parse.h"
#include "structures/prio_queue.hpp"
#include "structures/task_container.hpp"

int main(int argc, char* argv[]) {
  task_container<struct tasks> big_test;
  struct tasks info;
  info.name = "test";
  info.priority = 16;
  struct tasks info1;
  info1.name = "test";
  info1.priority = 1;
  struct tasks info2;
  info2.name = "test";
  info2.priority = 8;
  struct tasks info3;
  info3.name = "test";
  info3.priority = 2;
  struct tasks info4;
  info4.name = "test";
  info4.priority = 14;
  struct tasks info5;
  info5.name = "test";
  info5.priority = 7;
  struct tasks info6;
  info6.name = "test";
  info6.priority = 4;
  struct tasks info7;
  info7.name = "test";
  info7.priority = 9;
  struct tasks info8;
  info8.name = "test";
  info8.priority = 3;
  struct tasks info9;
  info9.name = "test";
  info9.priority = 10;

  big_test.add(info);
  big_test.add(info1);
  big_test.add(info2);
  big_test.add(info3);
  big_test.add(info4);
  big_test.add(info5);
  big_test.add(info6);
  big_test.add(info7);
  big_test.add(info8);
  big_test.add(info9);

  for (int i = 0; i < 10; i++) {
    std::cout << big_test[i].name << " : " << big_test[i].priority << std::endl;
  }

  prio_queue queue(big_test);
  std::cout << queue.get_size() << std::endl;
  readFile(queue);
  printToFile(queue);
  return 0;
}
