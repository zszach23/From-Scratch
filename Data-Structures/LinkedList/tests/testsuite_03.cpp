// ============================================================================
// LinkedList: testsuite_03.cpp
//
// Test Suite for LinkedList Get()
// ============================================================================

#include "LinkedList.hpp"
#include <gtest/gtest.h>

TEST(LL_Get, IndexOutOfBounds)
{
    int array[3] = {1, 2, 3};
    LinkedList<int> list(array, 3);

    EXPECT_EQ(list.Get(-1), 0);
    EXPECT_EQ(list.Get(4), 0);
}

TEST(LL_Get, IndexWithEmptyList)
{
    LinkedList<int> list;

    EXPECT_EQ(list.Get(0), 0);
    EXPECT_EQ(list.Get(1), 0);
    EXPECT_EQ(list.Get(-1), 0);
}

TEST(LL_Get, IndexWithOneItemInList)
{
    int array[1] = {1};
    LinkedList<int> list(array, 1);

    EXPECT_EQ(list.Get(0), 1);
    EXPECT_EQ(list.Get(1), 0);
}

TEST(LL_Get, IndexWithMultipleItemsInList)
{
    int array[5] = {1, 2, 3, 4, 5};
    LinkedList<int> list(array, 5);

    EXPECT_EQ(list.Get(0), 1);
    EXPECT_EQ(list.Get(1), 2);
    EXPECT_EQ(list.Get(2), 3);
    EXPECT_EQ(list.Get(3), 4);
    EXPECT_EQ(list.Get(4), 5);
    EXPECT_EQ(list.Get(5), 0);
}