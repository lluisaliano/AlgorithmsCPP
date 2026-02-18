#include <iostream>
#include <utility>
#include <vector>

template <typename T>
int partition(std::vector<T> &arr, int low, int high) {
  // We will take the pivot as the last element
  T pivot{arr[static_cast<std::size_t>(high)]};

  // i will keep the invariant that no element arr[i] <= pivot
  int i{low - 1};  // At the begining no element is known to be smaller or equal
  // to pivot, so i = -1;

  // We traverse all array elements minus the last, as it has the pivot.
  for (int j{low}; j < high; ++j) {
    if (arr[static_cast<std::size_t>(j)] <= pivot) {
      // If some element is smaller or equal than pivot,
      ++i;
      // We put that element at the begining of the array
      std::swap(arr[static_cast<size_t>(i)], arr[static_cast<size_t>(j)]);
    }
  }

  // Once done, we return pivot new index which is i+1 and we put it in position
  std::swap(arr[static_cast<size_t>(high)], arr[static_cast<size_t>(i + 1)]);

  return i+1;
}

template <typename T>
void quickSort(std::vector<T> &arr, int low, int high) {
  // If low is less than high, the subarray is not ordered yet
  if (low < high) {
    int pivot{partition(arr, low, high)}; // Pivot is on position here

    quickSort(arr, low, pivot-1); // So we do not need to pass it again
    quickSort(arr, pivot + 1, high);
  }
}

int main() {
  std::vector hola{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  quickSort(hola, 0, static_cast<int>(std::ssize(hola)-1));

  for (auto elem : hola) {
    std::cout << elem << '\t';
  }
  std::cout << '\n';
}
