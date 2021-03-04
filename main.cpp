#include <iostream>
#include "linked_list_lib/LinkedList.h"
#include "array_lib/Array.h"
#include "binary_heap_lib/BinaryHeap.h"

int main() {
    auto heap = BinaryHeap<int>();
    heap.add(5);
    heap.add(4);
    heap.add(6);
    std::cout << heap.contains(3) << std::endl;
    std::cout << heap.contains(4) << std::endl;
    heap.remove(4);
    std::cout << heap.contains(4) << std::endl;
}
