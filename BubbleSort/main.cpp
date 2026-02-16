#include <iostream>
#include <iterator>
#include <utility>

// BubbleSort
int main() {
  int array[]{6, 3, 2, 9, 7, 1, 5, 4, 8};
  constexpr int length{static_cast<int>(std::size(array))};

  for (int i{length}; i > 0; --i) {
    int j{0};
    while (j + 1 < i) {
      if (array[j] > array[j + 1]) {
        std::swap(array[j], array[j + 1]);
      }
      ++j;
    }
  }

  for (auto i{0}; i < length; ++i) {
    std::cout << array[i] << '\t';
  }
}
