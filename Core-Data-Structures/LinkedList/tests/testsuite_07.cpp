// ============================================================================
// LinkedList: testsuite_07.cpp
//
// Test Suite for LinkedList PeekFront()
// ============================================================================

#include "LinkedList.hpp"
#include <gtest/gtest.h>

TEST(LL_PeekFront, EmptyList)
{
    LinkedList<int> list;

    EXPECT_EQ(list.PeekFront(), 0);
}

TEST(LL_PeekFront, OneItemInList)
{
    int array[1] = {1};
    LinkedList<int> list(array, 1);

    EXPECT_EQ(list.PeekFront(), 1);
}

TEST(LL_PeekFront, MultipleItemsInList)
{
    int array[5] = {1, 2, 3, 4, 5};
    LinkedList<int> list(array, 5);

    EXPECT_EQ(list.PeekFront(), 1);
}