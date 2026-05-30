// ============================================================================
// LinkedList: testsuite_05.cpp
//
// Test Suite for LinkedList RemoveHead()
// ============================================================================

#include "LinkedList.hpp"
#include <gtest/gtest.h>

TEST(LL_RemoveHead, EmptyList)
{
    LinkedList<int> list;

    EXPECT_EQ(list.RemoveHead(), 0);
    EXPECT_EQ(list.Size(), 0);
}

TEST(LL_RemoveHead, OneItemInList)
{
    int array[1] = {1};
    LinkedList<int> list(array, 1);

    EXPECT_EQ(list.RemoveHead(), 1);
    EXPECT_EQ(list.Size(), 0);
}

TEST(LL_RemoveHead, MultipleItemsInList)
{
    int array[5] = {1, 2, 3, 4, 5};
    LinkedList<int> list(array, 5);

    EXPECT_EQ(list.RemoveHead(), 1);
    EXPECT_EQ(list.Size(), 4);

    EXPECT_EQ(list.RemoveHead(), 2);
    EXPECT_EQ(list.Size(), 3);

    EXPECT_EQ(list.RemoveHead(), 3);
    EXPECT_EQ(list.Size(), 2);

    EXPECT_EQ(list.RemoveHead(), 4);
    EXPECT_EQ(list.Size(), 1);

    EXPECT_EQ(list.RemoveHead(), 5);
    EXPECT_EQ(list.Size(), 0);
}