// ============================================================================
// LinkedList: testsuite_02.cpp
//
// Test Suite for LinkedList Prepend()
// ============================================================================

#include "LinkedList.hpp"
#include <gtest/gtest.h>

TEST(LL_Prepend, PrependWithEmptyList)
{
    LinkedList<int> list;

    list.Prepend(1);

    EXPECT_EQ(list.Get(0), 1);

    EXPECT_EQ(list.Size(), 1);
}

TEST(LL_Prepend, PrependWithOneItemInList)
{
    int array[1] = {1};
    LinkedList<int> list(array, 1);

    list.Prepend(2);

    EXPECT_EQ(list.Get(0), 2);
    EXPECT_EQ(list.Get(1), 1);

    EXPECT_EQ(list.Size(), 2);
}

TEST(LL_Prepend, PrependWithMultipleItemsInList)
{
    int array[5] = {1, 2, 3, 4, 5};
    LinkedList<int> list(array, 5);

    list.Prepend(100);

    EXPECT_EQ(list.Get(0), 100);
    EXPECT_EQ(list.Get(1), 1);
    EXPECT_EQ(list.Get(2), 2);
    EXPECT_EQ(list.Get(3), 3);
    EXPECT_EQ(list.Get(4), 4);
    EXPECT_EQ(list.Get(5), 5);

    EXPECT_EQ(list.Size(), 6);
}