#include <algorithm>
#include <cmath>
#include <cstddef>
#include <initializer_list>
#include <utility>
#include <vector>

// We use a namespace to store Heap algorithm
namespace Heap {
  class MaxHeap {
   private:
    std::vector<int> m_data{};

    void heapify(const int index, int maxLength = -1) {
      if (maxLength == -1) {
        maxLength = static_cast<int>(m_data.size());
      }
      if (index >= maxLength) {
        return;
      }

      int leftChild{2 * index + 1};
      int rightChild{2 * index + 2};

      int max{index};

      if (leftChild < maxLength && m_data[leftChild] > m_data[max]) {
        max = leftChild;
      }
      if (rightChild < maxLength && m_data[rightChild] > m_data[max]) {
        max = rightChild;
      }

      if (max == index) {
        return;
      }

      std::swap(m_data[index], m_data[max]);

      // Rerun heapify on the new position of the element (which is max as we
      // swapped them)
      heapify(max, maxLength); // max is the element passed on index, as the swapping exchanged the values
    }

   public:
    MaxHeap(std::initializer_list<int> values)
        : MaxHeap(std::vector<int>(values)) {}

    MaxHeap(std::vector<int> values) : m_data{std::move(values)} {
      // We have to call heapify on all elements that are not leafs
      int lastNotLeaf{static_cast<int>((m_data.size() / 2)) - 1}; // Last non leaf

      for (int i{lastNotLeaf}; i >= 0; --i) { // We do not call it on leafs as they already respect the heap property
        heapify(i);
      }
    }

    void insert(const int e) {
      m_data.push_back(e);

      int index = m_data.size() - 1;

      if (index == 0) { // There is only one element
        return;
      }

      int parent{static_cast<int>(((index - 1) / 2))};

      while (m_data[parent] < m_data[index] && index > 0) {
        std::swap(m_data[parent], m_data[index]);

        index = parent;
        parent = static_cast<int>((index / 2));
      }
    }

    void remove(const int index) {
      if (index < 0 || index >= static_cast<int>(getSize())) {
        return;
      }
      std::swap(m_data[index], m_data[m_data.size() - 1]);
      m_data.pop_back();
      heapify(index);
    }

    std::size_t getSize() const { return m_data.size(); }

    friend std::vector<int> heapSort(std::vector<int>&);
  };

  inline std::vector<int> heapSort(std::vector<int>& vector) {
    MaxHeap heap{vector};
    std::size_t nonSortedElems{heap.getSize()};

    while (nonSortedElems > 0) {
      std::swap(heap.m_data[0], heap.m_data[nonSortedElems - 1]); // We put the biggest value at the end, an consider that one ordered
      --nonSortedElems;

      heap.heapify(0, nonSortedElems); // Then we make the latest element of the array respect the heap property, constructing a heap again
    }

    return heap.m_data;
  }
}  // namespace Heap
