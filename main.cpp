#include <iostream>
#include "linked_list_lib/LinkedList.h"
#include "array_lib/Array.h"

int main() {
    Array<int> array = Array<int>();
    for (int i = 0; i < 30; i++) {
        array.pushBack(i);
    }
    for (int i = 0; i < 30; i++) {
        std::cout << array.get(i) << " ";
    }
    std::cout << std::endl;
    array.addAtPosition(100, 30);
    std::cout << array.toString();
    std::cout << std::endl;
    LinkedList<int> lista = LinkedList<int>();
    for (int i = 0; i < 30; i++) {
        lista.pushBack(i);
    }
    std::cout << lista.toString();
    std::cout << std::endl;
    lista.get(10);
    std::cout << lista.toString();
}
