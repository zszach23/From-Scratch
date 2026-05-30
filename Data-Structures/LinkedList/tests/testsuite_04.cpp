// ============================================================================
// LinkedList: testsuite_04.cpp
//
// Test Suite for LinkedList GetIndexOf()
// ============================================================================

#include "LinkedList.hpp"
#include <gtest/gtest.h>

TEST(LL_GetIndexOf, EmptyList)
{
    LinkedList<int> list;

    EXPECT_EQ(list.GetIndexOf(0), -1);
    EXPECT_EQ(list.GetIndexOf(1), -1);
    EXPECT_EQ(list.GetIndexOf(-1), -1);
}

TEST(LL_GetIndexOf, OneItemInList)
{
    int array[1] = {1};
    LinkedList<int> list(array, 1);

    EXPECT_EQ(list.GetIndexOf(1), 0);
    EXPECT_EQ(list.GetIndexOf(0), -1);
}

TEST(LL_GetIndexOf, MultipleItemsInList)
{
    int array[5] = {1, 2, 3, 4, 5};
    LinkedList<int> list(array, 5);

    EXPECT_EQ(list.GetIndexOf(1), 0);
    EXPECT_EQ(list.GetIndexOf(2), 1);
    EXPECT_EQ(list.GetIndexOf(3), 2);
    EXPECT_EQ(list.GetIndexOf(4), 3);
    EXPECT_EQ(list.GetIndexOf(5), 4);
}