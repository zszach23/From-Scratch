// ============================================================================
// LinkedList: testsuite_01.cpp
//
// Test Suite for LinkedList Constructors
// ============================================================================

#include "LinkedList.hpp"
#include <gtest/gtest.h>

TEST(LL_Constructor, DefaultConstructor)
{
    LinkedList<int> list;
    EXPECT_EQ(list.Size(), 0);
    EXPECT_EQ(list.Get(0), 0);
}

TEST(LL_Constructor, ArrayConstructor)
{
    int array[5] = {1, 2, 3, 4, 5};
    LinkedList<int> list(array, 5);
    
    EXPECT_EQ(list.Get(0), 1);
    EXPECT_EQ(list.Get(1), 2);
    EXPECT_EQ(list.Get(2), 3);
    EXPECT_EQ(list.Get(3), 4);
    EXPECT_EQ(list.Get(4), 5);
    EXPECT_EQ(list.Get(100), 0);
    EXPECT_EQ(list.Size(), 5);
}