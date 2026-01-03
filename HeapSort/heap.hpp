#include <algorithm>
#include <cmath>
#include <cstddef>
#include <initializer_list>
#include <utility>
#include <vector>

namespace Heap {
  class MaxHeap {
   private:
    std::vector<int> m_data{};

    void heapify(const int index, int maxLength=-1) {
      if (maxLength==-1) {
        maxLength = static_cast<int>(m_data.size());
      }
      if (index >= maxLength) {
        return;
      }

      int leftChild{2 * index + 1};
      int rightChild{2 * index + 2};

      int max{index};

      if (leftChild < maxLength &&
          m_data[leftChild] > m_data[max]) {
        max = leftChild;
      }
      if (rightChild < maxLength &&
          m_data[rightChild] > m_data[max]) {
        max = rightChild;
      }

      if (max == index) {
        return;
      }

      std::swap(m_data[index], m_data[max]);

      // Rerun heapify on the new position of the element (which is max as we
      // swapped them)
      heapify(max, maxLength);
    }

   public:
    MaxHeap(std::initializer_list<int> values) : m_data{values} {
      // We have to call heapify on all elements that are not leafs
      int lastNotLeaf{static_cast<int>((values.size() / 2)) - 1};

      for (int i{lastNotLeaf}; i >= 0; --i) {
        heapify(i);
      }
    }

    MaxHeap(std::vector<int>& values) : m_data{values} {
      // We have to call heapify on all elements that are not leafs
      int lastNotLeaf{static_cast<int>((values.size() / 2)) - 1};

      for (int i{lastNotLeaf}; i >= 0; --i) {
        heapify(i);
      }
    }

    void insert(const int e) {
      m_data.push_back(e);

      int index = m_data.size() - 1;
      int parent{static_cast<int>(std::floor((index - 1) / 2))};

      while (m_data[parent] < m_data[index] && index > 0) {
        std::swap(m_data[parent], m_data[index]);

        index = parent;
        parent = static_cast<int>(std::floor(index / 2));
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

    std::size_t getSize() { return m_data.size(); }

    friend std::vector<int> heapSort(std::vector<int>&);
  };

  inline std::vector<int> heapSort(std::vector<int>& vector) {
    MaxHeap heap{vector};
    std::size_t nonSortedElems{heap.getSize()};

    while (nonSortedElems > 0) {
      std::swap(heap.m_data[0], heap.m_data[nonSortedElems - 1]);
      --nonSortedElems;

      heap.heapify(0, nonSortedElems);
    }

    return heap.m_data;
  }
}  // namespace Heap
