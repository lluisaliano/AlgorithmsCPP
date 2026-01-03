#include "heap.hpp"
#include <iostream>
#include <ostream>

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& vector) {
  for (auto elem : vector) {
    out << elem << ' ';
  }
  out << '\n';
  return out;
}

int main() {
  Heap::MaxHeap heap{{5,4,2,6,1,6,7,3}};
  heap.insert(10);
  heap.remove(4);

  std::vector superCoolArray{{5,4,12,5,6,2,7,547,456,7456,3124,5123}};

  std::cout << superCoolArray << '\n';

  std::vector sortedSuperCoolArray{Heap::heapSort(superCoolArray)};

  std::cout << sortedSuperCoolArray << '\n';
}
