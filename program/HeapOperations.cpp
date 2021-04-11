#include "HeapOperations.h"

void HeapOperations::run() {
    active = true;
    while(active)
    {
        displayMenu();
        std::getline(std::cin, input);
        interpretInput();
    }
}

void HeapOperations::displayMenu() {
    std::string text = "OPERACJE NA KOPCU\n"
                       "1. Zbuduj z pliku\n"
                       "2. Stworz nowa liste\n"
                       "3. Dodaj element\n"
                       "4. Usun element\n"
                       "5. Znajdz element\n"
                       "6. Wyswietl\n"
                       "7. Wroc do menu glownego\n\n";
    std::cout << text;
}

void HeapOperations::interpretInput() {
    int option;
    try{
        option = std::stoi(input);
        switch(option){
            case 1:
                break;
            case 2:
                mHeap = heap();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
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
