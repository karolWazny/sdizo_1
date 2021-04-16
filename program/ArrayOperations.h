#ifndef SDIZO_1_ARRAYOPERATIONS_H
#define SDIZO_1_ARRAYOPERATIONS_H

#include <string>
#include <structures.h>

class ArrayOperations {
public:
    void run();
private:
    void displayMenu();
    void interpretInput();
    void fromFile();
    void displayArray();
    void addElement();
    void removeElement();
    void findElement();
    void timeMeasurment();
    void measureFindingTime();
    void measurePuttingTime();

    array tab = array();

    bool active = true;
    std::string input;
};


#endif //SDIZO_1_ARRAYOPERATIONS_H
