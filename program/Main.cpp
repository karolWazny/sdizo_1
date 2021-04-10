#include <iostream>
#include "Main.h"
#include "ArrayOperations.h"

int main(){
    auto program = Main();
    return program.run();
}

int Main::run() {
    displayGreeting();
    while(keepGoing)
    {
        displayMenu();
        std::getline(std::wcin, input);
        interpretInput();
        //system("cls");
    }
    return 0;
}

void Main::displayGreeting() {
    std::wcout << L"Witamy w programie." << std::endl << std::endl;
}

void Main::displayMenu() {
    String menuText = L"1. Operacje na tablicy.\n";
    menuText += L"2. Operacje na liscie.\n";
    menuText += L"3. Operacje na kopcu.\n";
    menuText += L"4. Operacje na drzewie czerwono-czarnym.\n";
    menuText += L"5. Zakoncz program.\n";
    std::wcout << menuText;
}

void Main::interpretInput() {
    int option;
    try{
        option = std::stoi(input);
        switch(option){
            case 1:
                arrayOperations();
                break;
            case 2:
                listOperations();
                break;
            case 3:
                heapOperations();
                break;
            case 4:
                rbTreeOperations();
                break;
            case 5:
                keepGoing = false;
                break;
            default:
                throw 4;
        }
    } catch (...) {
        std::wcout << L"Niewlasciwy symbol." << std::endl;
        return;
    }
}

void Main::arrayOperations() {
    auto operations = ArrayOperations();
    operations.run();
}

void Main::listOperations() {

}

void Main::heapOperations() {

}

void Main::rbTreeOperations() {

}
