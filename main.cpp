#include <iostream>
#include "linked_list_lib/LinkedList.h"

int main() {
    LinkedList<int> lista = LinkedList<int>();
    for (int i = 0; i < 30; i++) {
        lista.pushBack(i);
    }
    std::cout << lista.toString();
    std::cout << std::endl;
    lista.get(10);
    std::cout << lista.toString();
}
