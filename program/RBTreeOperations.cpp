#include "RBTreeOperations.h"

void RBTreeOperations::run() {
    active = true;
    while(active)
    {
        displayMenu();
        std::getline(std::cin, input);
        interpretInput();
    }
}

void RBTreeOperations::displayMenu() {
    std::string text = "OPERACJE NA DRZEWIE CZERWONO-CZARNYM\n"
                       "1. Zbuduj z pliku\n"
                       "2. Stworz nowe drzewo\n"
                       "3. Dodaj element\n"
                       "4. Usun element\n"
                       "5. Znajdz element\n"
                       "6. Wyswietl\n"
                       "7. Wroc do menu glownego\n\n";
    std::cout << text;
}

void RBTreeOperations::interpretInput() {
    int option;
    try{
        option = std::stoi(input);
        switch(option){
            case 1:
                break;
            case 2:
                tree = rbtree();
                break;
            case 3:
                addElement();
                break;
            case 4:
                removeElement();
                break;
            case 5:
                findElement();
                break;
            case 6:
                display();
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

void RBTreeOperations::addElement() {
    std::string text = "Podaj wartosc, ktora chcesz umiescic:\n";
    std::cout << text;
    std::getline(std::cin, input);
    int value = std::stoi(input);
    try{
        tree.put(value);
        text = "Dodano element ";
        text += std::to_string(value);
        text += ".\n";
    } catch (IndexOutOfBoundException& e) {
        text = "Niewlasciwy indeks!\n";
    }

    std::cout << text;
}

void RBTreeOperations::removeElement() {
    std::string text = "Podaj wartosc klucza, ktory chcesz usunac:\n";
    std::cout << text;
    std::getline(std::cin, input);
    int keyToRemove;
    keyToRemove = std::stoi(input);
    tree.removeKey(keyToRemove);
}

void RBTreeOperations::findElement() {
    std::string text = "Podaj element, ktory chcesz wyszukac:\n";
    std::cout << text;
    std::getline(std::cin, input);
    int value;
    value = std::stoi(input);
    bool contains = tree.containsKey(value);
    if(contains)
    {
        text = "Drzewo zawiera element o wartosci ";
    } else {
        text = "Drzewo nie zawiera elementu o wartosci ";
    }
    text += std::to_string(value);
    text += ".\n";
    std::cout << text;
}

void RBTreeOperations::display() {
    std::cout << tree.getRepresentation() << std::endl;
}
