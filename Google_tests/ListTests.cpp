
#include "gtest/gtest.h"
#include <linked_list_lib/LinkedList.h>

TEST(LinkedListTestSuite, ContainsFalse){ // 12/0/2020 -> 0
    auto list = LinkedList<int>();
    //ASSERT_FALSE(list.contains(5));
}

TEST(LinkedListTestSuite, PushFront){ // 12/0/2020 -> 0
    auto list = LinkedList<int>();
    list.pushFront(5);
    ASSERT_TRUE(list.get(0) == 5);
    list.pushFront(4);
    ASSERT_TRUE(list.get(1) == 5);
    ASSERT_TRUE(list.get(0) == 4);
}
