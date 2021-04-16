#ifndef SDIZO_1_LISTOPERATIONS_H
#define SDIZO_1_LISTOPERATIONS_H

#include <iostream>
#include <string>
#include <structures.h>

class ListOperations {
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
    std::string input;
    list linkedList;
};


#endif //SDIZO_1_LISTOPERATIONS_H
