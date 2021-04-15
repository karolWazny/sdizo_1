#include "ArrayOperations.h"
#include <iostream>

void ArrayOperations::run() {
    active = true;
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
            case 5:
                findElement();
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
    std::string text = "Podaj wartosc, ktora chcesz umiescic:\n";
    std::cout << text;
    std::getline(std::cin, input);
    int value = std::stoi(input);
    text = "Podaj pozycje, na ktorej chcesz dodac element\n"
                       "(uzyj 'last', zeby dodac na koncu,\n"
                       "lub 'first', zeby dodac na poczatku):\n";
    std::cout << text;
    std::getline(std::cin, input);
    try{
        int position;
        if(input == "first")
        {
            tab.pushFront(value);
            position = 0;
        } else if(input == "last")
        {
            position = tab.getLength();
            tab.pushBack(value);
        } else {
            position = std::stoi(input);
            tab.putAtPosition(value, position);
        }
        text = "Dodano element: ";
        text += std::to_string(value);
        text += " na pozycji o ideksie ";
        text += std::to_string(position);
        text += "\n";
    } catch (IndexOutOfBoundException& e) {
        text = "Niewlasciwy indeks!\n";
    }

    std::cout << text;
}

void ArrayOperations::removeElement() {
    std::string text = "Podaj pozycje, z ktorej chcesz usunac element:\n"
                       "(uzyj 'last', zeby usunac ostatni element,\n"
                       "lub 'first', zeby usunac pierwszy):\n";
    if(tab.getLength() == 0)
    {
        std::cout << "Nie mozna usunac elementu z pustej tablicy.\n"
                     "Operacje anulowano.\n";
        return;
    }
    std::cout << text;
    std::getline(std::cin, input);
    try{
        int position;
        if(input == "first")
        {
            position = 0;
            tab.removeFirst();
        } else if(input == "last")
        {
            position = tab.getLength();
            tab.removeLast();
        } else {
            position = std::stoi(input);
            if(position >= tab.getLength())
                throw IndexOutOfBoundException();
            tab.removeAt(position);
        }
        text = "Usunieto element na pozycji o ideksie ";
        text += std::to_string(position);
        text += "\n";
    } catch (IndexOutOfBoundException& e) {
        text = "Niewlasciwy indeks!\nOperacje anulowano.\n";
    }

    std::cout << text;
}

void ArrayOperations::findElement() {
    std::string text = "Podaj element, ktory chcesz wyszukac:\n";
    std::cout << text;
    std::getline(std::cin, input);
    int value;
    value = std::stoi(input);
    bool contains = tab.contains(value);
    if(contains)
    {
        text = "Tablica zawiera element o wartosci ";
    } else {
        text = "Tablica nie zawiera elementu o wartosci ";
    }
    text += std::to_string(value);
    text += ".\n";
    std::cout << text;
}
