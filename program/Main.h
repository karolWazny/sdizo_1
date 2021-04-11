#ifndef SDIZO_1_MAIN_H
#define SDIZO_1_MAIN_H

#include <string>


#include "ArrayOperations.h"
#include "ListOperations.h"

using String = std::wstring;

class Main
{
public:
    int run();
    void displayGreeting();
    void displayMenu();
    void interpretInput();
    void arrayOperations();
    void listOperations();
    void heapOperations();
    void rbTreeOperations();
private:
    bool keepGoing = true;
    String input;

    ArrayOperations arrayOperator;
    ListOperations listOperator;
};

#endif //SDIZO_1_MAIN_H
