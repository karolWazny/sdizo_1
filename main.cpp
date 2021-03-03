#include <iostream>
#include "linked_list_lib/LinkedList.h"
#include "array_lib/Array.h"
#include "binary_heap_lib/BinaryHeap.h"

int main() {
    auto heap = BinaryHeap<int>();
    heap.add(5);
    heap.add(4);
    heap.add(6);
}
