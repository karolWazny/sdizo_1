#include "ArrayOperations.h"
#include <iostream>
#include <cstdlib>
#include "TextFileReader.h"
#include "StopWatch.h"

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
                           "7. Pomiar czasu\n"
                           "8. Wroc do menu glownego\n\n";
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
                timeMeasurment();
                break;
            case 8:
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
    std::string text = "Wprowadz nazwe, sciezke wzgledem aktualnego folderu,\n"
                       "lub pelna sciezke do pliku:\n";
    std::cout << text;
    std::string filename;
    std::getline(std::cin, filename);
    try {
        TextFileReader reader;
        auto content = reader.fromFile(filename);
        tab = array();
        for(int i = 1; i <= content[0]; i++)
        {
            tab.pushBack(content[i]);
        }
    } catch(...) {
        std::cout << "Wystapil problem.\n"
                     "Operacje anulowano.\n";
    }
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

void ArrayOperations::timeMeasurment() {
    std::string text = "Co chcesz zmierzyc?\n"
                       "1. Czas wyszukania elementu.\n"
                       "2. Czas dodania elementu.\n"
                       "3. Czas usuwania elementu.\n";
    std::cout << text;
    std::getline(std::cin, input);
    int option = std::stoi(input);
    switch(option)
    {
        case 1:
            measureFindingTime();
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            std::cout << "Nieprawidlowa opcja.\nPomiar anulowano.\n";
            return;
    }
}

void ArrayOperations::measureFindingTime() {
    std::cout << "Dla ilu elementow chcesz zmierzyc czas wyszukiwania?\n"
                 "1. 2500\n"
                 "2. 5000\n"
                 "3. 12500\n"
                 "4. 25000\n"
                 "5. 50000\n";
    std::getline(std::cin, input);
    int option = std::stoi(input);
    int numberOfElements;
    switch(option)
    {
        case 1:
            numberOfElements = 2500;
            break;
        case 2:
            numberOfElements = 5000;
            break;
        case 3:
            numberOfElements = 12500;
            break;
        case 4:
            numberOfElements = 25000;
            break;
        case 5:
            numberOfElements = 50000;
            break;
        default:
            throw 4;
    }
    srand((unsigned)time(0));
    unsigned long long average = 0;
    for(int i = 0; i < 128; i++)
    {
        array measurementsArray;
        std::cout << "|";//todo
        for(int j = 0; j < numberOfElements; j++)
        {
            measurementsArray.pushBack(rand() % (numberOfElements/2));
        }
        int32_t seekedElement = rand() % (numberOfElements/2);
        StopWatch watch;
        bool contains;
        watch.start();
        contains = measurementsArray.contains(seekedElement);
        watch.stop();
        if(contains)
            average += watch.getLastMeasurmentMicrosec();
        else
        {
            average += watch.getLastMeasurmentMicrosec();
            watch.start();
        }
        if(!watch.getLastMeasurmentMicrosec())
        {
            i--;
            continue;
        }
    }
    std::cout << std::endl;
    average /= 128;
    std::cout << "Sredni czas wyszukania elementu\n"
                 "dla tablicy o dlugosci " << std::to_string(numberOfElements)
                 << " wynosi " << std::to_string(average)
                 << std::endl;
}

void ArrayOperations::measurePuttingTime() {

}

