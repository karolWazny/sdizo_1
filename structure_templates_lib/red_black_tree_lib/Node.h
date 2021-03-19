//
// Created by admin on 19.03.2021.
//

#ifndef SDIZO_1_NODE_H
#define SDIZO_1_NODE_H

template <typename T, typename U>
class Node
{
public:
    Node(T key, U value);
    U& getContent();
    T getKey();
private:
    T key;
    U value;
};

template<typename T, typename U>
U &Node<T, U>::getContent() {
    return value;
}

template<typename T, typename U>
Node<T, U>::Node(T key, U value) {
    this->key = key;
    this->value = value;
}

template<typename T, typename U>
T Node<T, U>::getKey() {
    return key;
}

#endif //SDIZO_1_NODE_H
