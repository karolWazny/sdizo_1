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
                removeElement();
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
    std::getline(std::cin, input);
    int position = std::stoi(input);//todo walidacja
    text = "Podaj wartosc, ktora chcesz umiescic:\n";
    std::cout << text;
    std::getline(std::cin, input);
    int value = std::stoi(input);//todo walidacja
    tab.putAtPosition(value, position);
    text = "Dodano element: ";
    text += std::to_string(value);
    text += " na pozycji o ideksie ";
    text += std::to_string(position);
    text += "\n";
    std::cout << text;
}

void ArrayOperations::removeElement() {

}
