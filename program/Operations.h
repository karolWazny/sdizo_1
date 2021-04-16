#ifndef SDIZO_1_OPERATIONS_H
#define SDIZO_1_OPERATIONS_H

#include <string>

class Operations {
public:
    void displayMenu(std::string&);
    void read();
    int readInt();
    int sizeChoiceMenu(int[], int);
protected:
    std::string input;
};


#endif //SDIZO_1_OPERATIONS_H
