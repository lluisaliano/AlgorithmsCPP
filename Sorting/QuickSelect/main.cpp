#include <cstddef>
#include <iostream>
#include <vector>
#include <utility>
#include <cassert>

template <typename T>
int Partition(std::vector<T> &arr, int begin, int end) {
  int i{begin - 1};

  T pivot = arr[static_cast<std::size_t>(end)];

  for (int j{begin}; j < end; ++j) {
    if (arr[static_cast<std::size_t>(j)] < pivot) {
      ++i;
      std::swap(arr[static_cast<std::size_t>(j)], arr[static_cast<std::size_t>(i)]);
    }
  }

  std::swap(arr[static_cast<std::size_t>(i + 1)],
            arr[static_cast<std::size_t>(end)]);

  return i + 1;
}

template <typename T>
T quickSelect(std::vector<T> &arr, int position, int begin, int end) {
  assert( (position <= end && position >= begin) && "Position is out of bonds");
  // There is only one element
  if (begin == end) {
    return arr[static_cast<std::size_t>(begin)];
  }

  int pivot{Partition(arr, begin, end)};

  if (pivot == position) {
    return arr[static_cast<std::size_t>(position)];
  }

  if (position > pivot) {
    return quickSelect(arr, position, pivot + 1, end);
  } else  {
    return quickSelect(arr, position, begin, pivot - 1);
  }

}

int main() {
  std::vector arr{4, 6, 7, 234, 89, 4, 3, 2, 23};

  int fourthSmallestNumber{
      quickSelect(arr, 40, 0, static_cast<int>(arr.size() - 1))};

  std::cout << fourthSmallestNumber << '\n';

  for (auto elem : arr) {
    std::cout << elem << '\t';
  }

  std::cout << '\n';
}
