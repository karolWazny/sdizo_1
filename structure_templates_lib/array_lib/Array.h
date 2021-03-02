//
// Created by admin on 02.03.2021.
//

#ifndef SDIZO_1_ARRAY_H
#define SDIZO_1_ARRAY_H
#include <memory>
#include <string>
template <typename T>
class Array
{
public:
    Array<T>();
    void addAtPosition(T, const int);
    void swap(const int, const int);
    T remove(const int);
    void pushBack(T);
    T get(const int index);
    bool isEmpty();
    int getLength();
    std::string toString();
private:
    std::unique_ptr<T[]> elements;
    int length;
};

template <typename T>
Array<T>::Array()
{
    length = 0;
    elements = std::make_unique<T[]>(length);
}

template<typename T>
void Array<T>::pushBack(T element)
{
    auto buffer = std::make_unique<T[]>(length + 1);
    for(int i = 0; i < length; i++)
    {
        buffer[i] = elements[i];
    }
    buffer[length] = element;
    length++;
    elements = std::move(buffer);
}

template <typename T>
T Array<T>::get(const int index)
{
    return elements[index];
}

template <typename T>
T Array<T>::remove(const int index)
{
    auto buffer = elements[index];
    auto newArray = std::make_unique<T[]>(length - 1);
    int newArrayCount = 0;
    for(int i = 0; i < length; i++, newArrayCount++)
    {
        if(i == index)
        {
            newArrayCount--;
            continue;
        }
        newArray[newArrayCount] = elements[i];
    }
    elements = std::move(newArray);
    length--;
    return buffer;
}

template<typename T>
void Array<T>::swap(const int index1, const int index2)
{
    const auto buffer = elements[index1];
    elements[index1] = elements[index2];
    elements[index2] = buffer;
}

template<typename T>
void Array<T>::addAtPosition(T element, const int index)
{
    if(index >= length)
    {
        pushBack(element);
        return;
    }
    auto newArray = std::make_unique<T[]>(length + 1);
    int newArrayCount = 0;
    for(int i = 0; i < length; i++, newArrayCount++)
    {
        if(i == index)
        {
            newArray[newArrayCount] = element;
            newArrayCount++;
        }
        newArray[newArrayCount] = elements[i];
    }
    elements = std::move(newArray);
    length++;
}

template <typename T>
bool Array<T>::isEmpty()
{
    return !length;
}

template <typename T>
int Array<T>::getLength()
{
    return length;
}

template <typename T>
std::string Array<T>::toString()
{
    std::string output = "[";
    if(length)
    {
        output += std::to_string(elements[0]);
    }
    for(int i = 1; i < length; i++)
    {
        output += ", " + std::to_string(elements[i]);
    }
    output += "]";
    return output;
}

#endif //SDIZO_1_ARRAY_H
