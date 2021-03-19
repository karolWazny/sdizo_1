//
// Created by admin on 19.03.2021.
//

#ifndef SDIZO_1_REDBLACKTREE_H
#define SDIZO_1_REDBLACKTREE_H

template <typename T, typename U>
class RedBlackTree
{
public:
    void put(T key, U value);
    bool containsKey(T key);
    bool containsValue(U value);
private:
};

template<typename T, typename U>
void RedBlackTree<T, U>::put(T key, U value) {

}

template<typename T, typename U>
bool RedBlackTree<T, U>::containsKey(T key) {
    return true;
}

template<typename T, typename U>
bool RedBlackTree<T, U>::containsValue(U value) {
    return true;
}

#endif //SDIZO_1_REDBLACKTREE_H
