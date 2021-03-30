#include "gtest/gtest.h"
#include <red_black_tree_lib/node_util/NodeRotator.h>
#include <red_black_tree_lib/nodes/SimpleFactory.h>

TEST(NodeRotatorSuite, Compilation){
    auto node = SimpleFactory<int, int>().createNode(2, 2);
    auto rotator = NodeRotator<int, int>();
}

