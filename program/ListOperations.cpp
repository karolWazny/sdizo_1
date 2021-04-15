#include "ListOperations.h"

void ListOperations::run() {
    active = true;
    while(active)
    {
        displayMenu();
        std::getline(std::cin, input);
        interpretInput();
    }
}

void ListOperations::displayMenu() {
    std::string text = "OPERACJE NA LISCIE\n"
                       "1. Zbuduj z pliku\n"
                       "2. Stworz nowa liste\n"
                       "3. Dodaj element\n"
                       "4. Usun element\n"
                       "5. Znajdz element\n"
                       "6. Wyswietl\n"
                       "7. Wroc do menu glownego\n\n";
    std::cout << text;
}

void ListOperations::interpretInput() {
    int option;
    try{
        option = std::stoi(input);
        switch(option){
            case 1:
                break;
            case 2:
                linkedList = list();
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

void ListOperations::addElement() {
    std::string text = "Podaj wartosc, ktora chcesz umiescic:\n";
    std::cout << text;
    std::getline(std::cin, input);
    int value = std::stoi(input);
    text = "Podaj wartosc, po ktorej chcesz dodac element\n"
           "(uzyj 'last', zeby dodac na koncu,\n"
           "lub 'first', zeby dodac na poczatku):\n";
    std::cout << text;
    std::getline(std::cin, input);
    try{
        std::string sideText;
        if(input == "first")
        {
            linkedList.pushFront(value);
            sideText = " na poczatku listy.\n";
        } else if(input == "last")
        {
            linkedList.pushBack(value);
            sideText = " na koncu listy.\n";
        } else {
            int predecessor = std::stoi(input);
            if(linkedList.contains(predecessor)){
                sideText = " po elemencie ";
                sideText += std::to_string(predecessor);
                sideText += ".\n";
            } else {
                sideText = " na poczatku listy.\n";
            }
            linkedList.putAfter(predecessor, value);
        }
        text = "Dodano element ";
        text += std::to_string(value);
        text += sideText;
    } catch (IndexOutOfBoundException& e) {
        text = "Niewlasciwy indeks!\n";
    }

    std::cout << text;
}

void ListOperations::removeElement() {
    std::string text = "Podaj wartosc klucza, ktory chcesz usunac:\n"
                       "(uzyj 'last', zeby usunac ostatni element,\n"
                       "lub 'first', zeby usunac pierwszy):\n";
    try{
        if(linkedList.isEmpty())
            throw IndexOutOfBoundException();
        int keyToRemove;
        std::cout << text;
        std::getline(std::cin, input);
        if(input == "first")
        {
            linkedList.removeFirst();
            text = "Usunieto pierwszy element.\n";
        } else if(input == "last")
        {
            linkedList.removeLast();
            text = "Usunieto ostatni element.\n";
        } else {
            keyToRemove = std::stoi(input);
            bool removed = linkedList.remove(keyToRemove);
            if(removed){
                text = "Usunieto element o wartosci ";
            } else {
                text = "Lista nie zawierala elementu o wartosci ";
            }
            text += std::to_string(keyToRemove);
            text += ".\n";
        }
    } catch (IndexOutOfBoundException& e) {
        text = "Nie mozna usunac elementu z pustej listy.\n"
               "Operacje anulowano.\n";
    }

    std::cout << text;
}

void ListOperations::findElement() {
    std::string text = "Podaj element, ktory chcesz wyszukac:\n";
    std::cout << text;
    std::getline(std::cin, input);
    int value;
    value = std::stoi(input);
    bool contains = linkedList.contains(value);
    if(contains)
    {
        text = "Lista zawiera element o wartosci ";
    } else {
        text = "Lista nie zawiera elementu o wartosci ";
    }
    text += std::to_string(value);
    text += ".\n";
    std::cout << text;
}

void ListOperations::display() {
    std::cout << linkedList.toString() << std::endl;
}
