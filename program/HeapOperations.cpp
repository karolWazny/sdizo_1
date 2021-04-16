#include "HeapOperations.h"
#include "TextFileReader.h"

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
    std::string text = "OPERACJE NA KOPCU MAKSYMALNYM\n"
                       "1. Zbuduj z pliku\n"
                       "2. Stworz nowy kopiec\n"
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
                fromFile();
                break;
            case 2:
                mHeap = heap();
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

void HeapOperations::addElement() {
    std::string text = "Podaj wartosc, ktora chcesz umiescic:\n";
    std::cout << text;
    std::getline(std::cin, input);
    int value = std::stoi(input);
    mHeap.add(value);

    text = "Dodano do kopca wartosc ";
    text += std::to_string(value);
    text += ".\n";
    std::cout << text;
}

void HeapOperations::display() {
    //todo zaimplementowac sensowny sposob prezentacji kopca
}

void HeapOperations::removeElement() {
    std::string text = "Podaj wartosc klucza, ktory chcesz usunac\n"
                       "(uzyj 'max', zeby usunac element z korzenia kopca):\n";
    std::cout << text;
    std::getline(std::cin, input);
    try{
        int keyToRemove;
        if(!mHeap.getSize())
            throw IndexOutOfBoundException();
        if(input == "max")
        {
            keyToRemove = mHeap.extractMax();
            text = "Usunieto pierwszy element o wartosci ";
        } else {
            keyToRemove = std::stoi(input);
            bool removed = mHeap.remove(keyToRemove);
            if(removed){
                text = "Usunieto element o wartosci ";
            } else {
                text = "Kopiec nie zawieral elementu o wartosci ";
            }
        }
        text += std::to_string(keyToRemove);
        text += ".\n";
    } catch (IndexOutOfBoundException& e) {
        text = "Niewlasciwy indeks!\n";
    }

    std::cout << text;
}

void HeapOperations::findElement() {
    std::string text = "Podaj element, ktory chcesz wyszukac:\n";
    std::cout << text;
    std::getline(std::cin, input);
    int value;
    value = std::stoi(input);
    bool contains = mHeap.contains(value);
    if(contains)
    {
        text = "Kopiec zawiera element o wartosci ";
    } else {
        text = "Kopiec nie zawiera elementu o wartosci ";
    }
    text += std::to_string(value);
    text += ".\n";
    std::cout << text;
}

void HeapOperations::fromFile() {
    std::string text = "Wprowadz nazwe, sciezke wzgledem aktualnego folderu,\n"
                       "lub pelna sciezke do pliku:\n";
    std::cout << text;
    std::string filename;
    std::getline(std::cin, filename);
    try {
        TextFileReader reader;
        auto content = reader.fromFile(filename);
        mHeap = heap();
        for(int i = 1; i <= content[0]; i++)
        {
            mHeap.add(content[i]);
        }
    } catch(...) {
        std::cout << "Wystapil problem.\n"
                     "Operacje anulowano.\n";
    }
}
