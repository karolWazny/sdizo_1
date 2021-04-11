#ifndef SDIZO_1_HEAPOPERATIONS_H
#define SDIZO_1_HEAPOPERATIONS_H

#include <iostream>
#include <string>
#include <structures.h>

class HeapOperations {
public:
    void run();
private:
    void displayMenu();
    void interpretInput();
    void addElement();
    void display();
    void removeElement();
    void findElement();

    bool active;
    std::string input;
    heap mHeap;
};


#endif //SDIZO_1_HEAPOPERATIONS_H
