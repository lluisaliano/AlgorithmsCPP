
#include <iterator>
#include <utility>
#include <iostream>


int main() {
  int array[]{30, 50, 20, 10, 40};
  constexpr int length{static_cast<int>(std::size(array))};

  for (int i{0}; i < length; ++i) {
    int minIndex{i};
    for (int j{minIndex+1}; j < length; ++j) {
      if (array[j] < array[minIndex]) {
        minIndex = j;
      }
    }
    std::swap(array[i], array[minIndex]);
  }

  for (int i{0}; i < length; ++i) {
    std::cout << array[i] << '\t';
  }
}
