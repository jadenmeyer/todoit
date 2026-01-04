#ifndef PRIO_QUEUE
#define PRIO_QUEUE

// higher priority = first

template <typename T, int prio>
class prio_queue {
 private:
  T* top;  // ptr to first element
 public:
  prio_queue();
  ~prio_queue();
};

#endif  // !prio_queue
