#ifndef TASK_CONTAINER
#define TASK_CONTAINER

template <typename T>
class task_container {
 private:
  int curr_size = 0;
  int max = 1024;  // current max size will change

  T* arr = new T[1024];  // array of size T on Heap

  void expand() {  // 2x size of the array
    this->max *= 2;
    T* temp = new T[max];
    for (int i = 0; i < curr_size; i++) {
      temp[i] = arr[i];
    }
    delete[] this->arr;
    this->arr = temp;
  }

 public:
  task_container() = default;
  task_container(T value) {
    curr_size += 1;
    this->arr[0] = value;
  }
  ~task_container() { delete[] arr; }

  T& operator[](int idx) {  // at index
    return arr[idx];
  }

  T& operator[](int idx) const { return arr[idx]; }

  T at(int idx) {
    if (idx > curr_size - 1) {
      return idx;
    } else {
      return arr[idx];
    }
  }  // same as [] but with bound checks

  int size() const { return this->curr_size; }

  void add(const T& elt) {  // make reutrn bool sometime
    if (this->curr_size >= this->max) {
      expand();
    }
    this->arr[curr_size] = elt;
    this->curr_size += 1;
  }
};

#endif  // !TASK_CONTAINER
