#include "structures/task_container.hpp"

int main(int argc, char* argv[]) {
  /* std::cout << "hello world" << std::endl;
   task_container<int> test;
   task_container<int> testy(1);

   std::cout << testy[0] << std::endl;
   std::cout << testy.at(0) << std::endl;
 */
  task_container<int> big_test;
  for (int i = 0; i < 20000; i++) {
    big_test.add(i);
  }

  return 0;
}
