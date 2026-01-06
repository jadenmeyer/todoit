#ifndef PRIO_QUEUE
#define PRIO_QUEUE

#include <stdexcept>
#include <string>

#include "task_container.hpp"

// task template
struct tasks {
  std::string name;
  int priority;
};

// higher priority = first
// limit priority to 255
class prio_queue {
 private:
  tasks* top;  // ptr to first element
  int max = 10;
  tasks* arr = new tasks[max];  // init to 1000
  int size = 0;                 // init to 0

  constexpr int left(int idx) const { return 2 * idx + 1; }
  constexpr int right(int idx) const { return 2 * idx + 2; }

  void expand() {
    this->max *= 2;
    tasks* temp = new tasks[this->max];
    for (int i = 0; i < this->size - 1; i++) {
      temp[i] = this->arr[i];
    }
    delete[] this->arr;
    this->arr = temp;
  }

 public:
  // treat this as a make-heap
  // prio_queue() = default;
  prio_queue(tasks& task) {
    this->arr[0] = task;
    this->size++;
  }
  prio_queue(task_container<tasks>& arrTask) {
    for (int i = 0; i < arrTask.size(); i++) {
      this->insert(arrTask[i]);
    }
  }
  void insert(tasks& task) {
    if (this->size >= this->max) {
      this->expand();
    }
    this->arr[this->size] = task;
    // rebalance(this->size);  wont work here
    heapify_insert(this->size);
    this->size++;
  }

  bool is_empty() const { return this->size > 0 ? false : true; }
  void heapify_insert(int idx) {
    while (idx > 0) {
      int parent = (idx - 1) / 2;
      if (this->arr[idx].priority > this->arr[parent].priority) {
        tasks temp = this->arr[parent];
        this->arr[parent] = this->arr[idx];
        this->arr[idx] = temp;
        idx = parent;
      } else {
        break;
      }
    }
  }
  tasks extract_max() {
    tasks task;

    task = this->arr[0];
    this->arr[0] = this->arr[this->size - 1];
    this->rebalance(0);
    this->size--;

    return task;
  }
  tasks get_max() const {
    if (this->size < 1) {
      throw std::out_of_range("heap too small");
    }
    return this->arr[0];  // top of heap
  }

  int get_size() const { return this->size; }

  void print() {}

  void rebalance(int idx) {
    if (idx >= this->size) {
      return;
    }
    int left = this->left(idx);
    int right = this->right(idx);
    int largest = idx;
    if (left<this->size&& this->arr[left].priority> this->arr[idx].priority) {
      largest = left;
    }
    if (right<this->size&& this->arr[right].priority> this->arr[largest]
            .priority) {
      largest = right;
    }
    if (largest != idx) {
      tasks temp = this->arr[idx];
      this->arr[idx] = this->arr[largest];
      this->arr[largest] = temp;
      rebalance(largest);
    }
  }
  ~prio_queue() { delete[] this->arr; }
};

#endif  // !prio_queue
