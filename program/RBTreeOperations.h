#ifndef SDIZO_1_RBTREEOPERATIONS_H
#define SDIZO_1_RBTREEOPERATIONS_H

#include <structures.h>
#include <iostream>
#include <string>

class RBTreeOperations {
public:
    void run();
private:
    void displayMenu();
    void interpretInput();
    void addElement();
    void removeElement();
    void findElement();
    void display();
    void fromFile();

    bool active;

    rbtree tree;
    std::string input;
};


#endif //SDIZO_1_RBTREEOPERATIONS_H
