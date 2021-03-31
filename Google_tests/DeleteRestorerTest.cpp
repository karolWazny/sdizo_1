#include "gtest/gtest.h"
#include <red_black_tree_lib/nodes/RBFactory.h>
#include <red_black_tree_lib/rbutil/DeletePropertyRestorer.h>

TEST(DeleteRestorerSuite, Compilation){
    auto restorer = DeletePropertyRestorer<int, int>();
}

TEST(DeleteRestorerSuite, SuccessorWasRed){
    auto restorer = DeletePropertyRestorer<int, int>();
}