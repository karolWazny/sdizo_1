#include "ArrayOperations.h"
#include <iostream>

void ArrayOperations::run() {
    while(active)
    {
        displayMenu();
        std::getline(std::cin, input);
        interpretInput();
    }
}

void ArrayOperations::displayMenu() {
    std::string menuText = "TABLICA DYNAMICZNA\n"
                           "1. Zbuduj z pliku\n"
                           "2. Stworz nowa tablice\n"
                           "3. Dodaj element\n"
                           "4. Usun element\n"
                           "5. Znajdz element\n"
                           "6. Wyswietl\n"
                           "7. Wroc do menu glownego\n\n";
    std::cout << menuText;

}

void ArrayOperations::interpretInput() {
    int option;
    try{
        option = std::stoi(input);
        switch(option){
            case 1:
                fromFile();
                break;
            case 2:
                tab = array();
                break;
            case 3:
                addElement();
                break;
            case 4:
                break;
            case 6:
                displayArray();
                break;
            case 7:
                active = false;
                break;
            default:
                throw 4;
        }
    } catch (...) {
        std::wcout << L"Niewlasciwy symbol." << std::endl;
        return;
    }
}

void ArrayOperations::fromFile() {

}

void ArrayOperations::displayArray() {
    std::cout << tab.toString() << std::endl << std::endl;
}

void ArrayOperations::addElement() {
    std::string text = "Podaj pozycje, na ktorej chcesz dodac element:\n";
    std::cout << text;
}
